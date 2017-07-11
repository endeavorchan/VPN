/*************************************************************************
	> File Name: mutex.h
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Jul 2017 05:42:55 PM UTC
 ************************************************************************/

#ifndef _MUTEX_H
class Mutex 
{
public:
    Mutex();
    ~Mutex();

private:
    pthread_mutex_t _lock;
};

#define _MUTEX_H
#endif
