/*************************************************************************
	> File Name: RingBuffer.h
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Jun 2017 07:53:24 PM UTC
 ************************************************************************/

#ifndef _RINGBUFFER_H

namespace lib
{

template<typename T, int QUEUESIZE>
class RingBuffer 
{

public:
    ~RingBuffer();

protected:

private:
    T m_Buffer[QUEUESIZE];

    int m_Head, m_Tail;
    bool m_Full, m_Empty;

    pthread_mutex_t m_Lock;
    pthread_cond_t m_NotFull, m_NotEmpty;  

    // User can only call init function to create RingBuffer
    //
    RingBuffer();

    // Disable compiler-generated members
    //
    RingBuffer(const RingBuffer&) = delete;
    RingBuffer& operator =(const RingBuffer&) = delete;
};

RingBuffer::RingBuffer()
{
    m_Head = 0;
    m_Tail = 0;
    m_Full = false;
    m_Empty = true;
    
    pthread_mutex_init(&m_Lock, nullptr);

    pthread_cond_init(&m_NotFull, nullptr);
    pthread_cond_init(&m_NotEmpty, nullptr);
}

RingBuffer::~RingBuffer()
{
    pthread_mutex_destroy(&m_Lock);

    pthread_cond_destroy(&m_NotEmpty);
    pthread_cond_destroy(&m_NotFull);
}

} // namespace lib

#define _RINGBUFFER_H
#endif
