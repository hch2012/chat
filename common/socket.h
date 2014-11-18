#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

//http://www.cnblogs.com/-Lei/archive/2012/09/04/2670942.html
class Socket{
private:
	int sock_fd;
	struct sockaddr_in sock_addr;
public:
	Socket();
	virtual ~Socket();


	//common method
	bool _create();

	//server method
	bool _bind(const int port);
	bool _listen(const int max_connection) const;
	bool _accept(Socket &client) const;

	//client method
	bool _connect(const std::string &host,const int port);

	//transmission data method
	int _recv(Socket& socket ,std::string &message) const;
	bool _send(Socket& socket,const std::string &message) const;
	void setNonBlock(const bool flag);
	bool validate() const;
};

#endif
