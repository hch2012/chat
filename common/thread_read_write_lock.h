#ifndef THREAD_READ_WRITE_LOCK_H
#define THREAD_READ_WRITE_LOCK_H

#include <pthread.h>

class ThreadReadWriteLock
{
    public:
        ThreadReadWriteLock();
        ~ThreadReadWriteLock();

        bool SetReadLock();
        bool SetWriteLock();
        void UnLock();

    private:
        pthread_rwlock_t readWriteLock;
};

#endif