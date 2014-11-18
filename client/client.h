#ifndef CLIENT_H
#define CLIENT_H

#include "../common/socket.h"
class Client:public Socket{
public:
	Client(std::string &host,int port);
	virtual ~Client();
	int _recv(std::string &message);
	bool _send(const std::string &message);
};

#endif