/*************************************************************************
	> File Name: RingBuffer.h
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Jun 2017 07:53:24 PM UTC
 ************************************************************************/

#ifndef _RINGBUFFER_H

namespace lib {

template<typename T, int QUEUESIZE>
class RingBuffer {

public:

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

}

}

#define _RINGBUFFER_H
#endif
