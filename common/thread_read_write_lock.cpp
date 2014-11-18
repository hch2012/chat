#include "thread_read_write_lock.cpp"
#include <pthread.h>

ThreadReadWriteLock::ThreadReadWriteLock(){
	pthread_rwlock_init(&readWriteLock ,NULL);
};
ThreadReadWriteLock::~ThreadReadWriteLock(){
	pthread_rwlock_destroy(&readWriteLock);
};

bool ThreadReadWriteLock::SetReadLock(){
	pthread_rwlock_rdlock(&readWriteLock);

};
bool ThreadReadWriteLock::SetWriteLock(){
	pthread_rwlock_wrlock(readWriteLock);
};
void ThreadReadWriteLock::UnLock(){
	pthread_rwlock_unlock(&readWriteLock)
};