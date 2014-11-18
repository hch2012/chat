#ifndef SERVICE_H
#define SERVICE_H

#include "../common/socket.h"
#include <stdio.h>
#include <stdlib.h>
#include "../common/thread_read_write_lock.h"

class Service:public Socket{
public:
    ServerSocket(const int port);
    ServerSocket();
    virtual ~ServerSocket();

    void _accept(Socket& socket);
    //run server to connect multi-clients
    void run();

private:
    //accept multi-clients
    bool _accept();
    void addClient(Socket* clientSocket);
    static void deleteClient(Socket* clientSocket);
    static void* processMessage(void* arg);
    static void sendMsgToAllUsers(const std::string& message);

    static list<Socket*> clientSockets;
    static bool serviceFlag;
    //use thread-read-write-lock to synchronize threads
    static ThreadReadWriteLock readWriteLock;
};


#endif