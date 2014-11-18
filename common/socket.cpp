#include "socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
Socket::Socket():sock_fd(-1){
}

Socket::~Socket(){

}

bool Socket::_create(){
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(validate())
		return true;
	else
		return false;
}
bool Socket::_bind(const int port){
	if(!validate())
		return false;
	memset(&sock_addr,0,sizeof(sock_addr));
	sock_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	sock_addr.sin_port=htons(port);
	sock_addr.sin_family=AF_INET;
	if(bind(sock_fd,(struct sockaddr*)&sock_addr,sizeof(sock_addr))==-1)
		return false;
	else
		return true;
}


bool Socket::_listen(const int max_connection) const{
	if(!validate())
		return false;
	if(listen(sock_fd,max_connection)==-1)
		return false;
	else
		return true;
}

bool Socket::_accept(Socket &client) const{
	if(!validate())
		return false;
	int clientLength=sizeof(client.sock_addr);
	client.sock_fd=accept(sock_fd,(struct sockaddr*)&(client.sock_addr),(socklen_t*)&clientLength);
	if(client.sock_fd==-1){
		return false;
	}
	else
		return true;
}

//client method
bool Socket::_connect(const std::string &host,const int port){
	if(!validate())
		return false;
	memset(&sock_addr,0,sizeof(sock_addr));
	inet_pton(AF_INET,host.c_str(),&sock_addr.sin_addr);
	sock_addr.sin_port=htons(port);
	sock_addr.sin_family=AF_INET;
	if(::connect(sock_fd,(struct sockaddr*)&sock_addr,sizeof(sock_addr))==-1){
		return false;
	}
	else
		return true;
}

//transmission data method
int Socket::_recv(Socket& socket ,std::string &message) const{
	if(!validate())
		return false;
	char buff[4096];
	message.clear();
	memset(buff,0,sizeof(buff));
	int n= recv(socket.sock_fd,buff,sizeof(buff),0);
	if(n==0)
		return 0;
	message=buff;
}	
bool Socket::_send(Socket& socket,const std::string &message) const{
	if(!validate())
		return false;
	int result=send(socket.sock_fd,message.c_str(),strlen(message.c_str()),0);
	return result!=-1;

}
void Socket::setNonBlock(const bool flag){
	if(validate()){
		int opts=fcntl(sock_fd,F_GETFL);
		if(opts<0){
			return;
		}
		if(flag){
			opts |= O_NONBLOCK;
		}
		else{
			opts &=(~O_NONBLOCK);
		}
		fcntl(sock_fd,F_SETFL,opts);
	}

}


bool Socket::validate() const{
	return sock_fd!=-1;
}
