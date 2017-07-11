#pragma once

template<typename T, size_t BufSize>
RingBufferNoLock<T, BufSize>::RingBufferNoLock()
{
    m_Head = 0;
    m_Tail = 0;
    m_Full = false;
    m_Empty = true;
}

template<typename T, size_t BufSize>
void RingBufferNoLock<T, BufSize>::push(const T& in)
{
    m_Buffer[m_Tail] = in;
    m_Tail++;
    if (m_Tail == BufSize)
    {
        m_Tail = 0;
    }

    if (m_Tail == m_Head)
    {
        m_Full = true;
    }
    m_Empty = false;
}

template<typename T, size_t BufSize>
T RingBufferNoLock<T, BufSize>::pop()
{
    T out = m_Buffer[m_Head];
    m_Head++;
    if (m_Head == BufSize)
    {
        m_Head = 0;
    }

    if (m_Head == m_Tail)
    {
        m_Empty = true;
    }
    m_Full = false;
    return out;

}

template<typename T, size_t BufSize>
RingBuffer<T, BufSize>::RingBuffer():RingBufferNoLock<T, BufSize>()
{
}

template<typename T, size_t BufSize>
RingBuffer<T, BufSize>::~RingBuffer()
{
}

template<typename T, size_t BufSize>
void RingBuffer<T, BufSize>::Produce(const T &val)
{
    std::unique_lock<std::mutex> ulock(m_Lock);
    while (this->isFull())
    {
        m_NotFull.wait(ulock);
    }
    push(val);
    m_NotEmpty.notify_one();
}

template<typename T, size_t BufSize>
T RingBuffer<T, BufSize>::Consume()
{
    std::unique_lock<std::mutex> ulock(m_Lock);
    while (this->isEmpty())
    {
        m_NotEmpty.wait(ulock);
    }

    T ret = this->pop();
    m_NotFull.notify_one();
    return ret;
}


