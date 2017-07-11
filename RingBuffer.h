/*************************************************************************
	> File Name: RingBuffer.h
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Jun 2017 07:53:24 PM UTC
 ************************************************************************/

#pragma once

//namespace lib
//{

template<typename T, size_t BufSize>
class RingBufferNoLock
{
public:
    RingBufferNoLock();

    void push(const T& val);
    T pop();

    bool isFull()
    {
        return m_Full;
    }

    bool isEmpty()
    {
        return m_Empty;
    }

    virtual ~RingBufferNoLock(){}

private:
    T m_Buffer[BufSize];
    int m_Head, m_Tail;
    bool m_Full, m_Empty;
};

template<typename T, size_t BufSize>
class RingBuffer : RingBufferNoLock<T, BufSize> 
{
public:
    RingBuffer();
    ~RingBuffer();

    void Produce(const T &val);
    T Consume();

private:
    std::mutex m_Lock;
    std::condition_variable m_NotFull, m_NotEmpty;  

    // Disable compiler-generated members
    //
    RingBuffer(const RingBuffer&) = delete;
    RingBuffer& operator =(const RingBuffer&) = delete;
};

//} // namespace lib

