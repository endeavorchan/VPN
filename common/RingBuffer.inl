#pragma once

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

void Produce(T &val)
{
    pthread_mutex_lock(_lock);
}
