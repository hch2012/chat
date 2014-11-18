#include "client.h"
#include <stdio.h>

Client::Client(std::string &host,int port){
	if(!Socket::_create()){
		printf("create error\n");
	}
	;
	if(!Socket::_connect(host,port)){
		printf("_connect error\n");
	}
}

Client::~Client(){

}

bool Client::_send(const std::string &message){
	return Socket::_send(static_cast<Socket&>(*this),message);

}

int Client::_recv(std::string &message){
	return Socket::_recv(static_cast<Socket&>(*this),message);
}