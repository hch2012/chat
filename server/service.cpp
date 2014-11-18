#include "service.h"
#include "my_exception.h"


ServerSocket::ServerSocket(const int port){
	if(!Socket::_create())
		throw MyException("create error!");
	if(!Socket::_bind(port))
		throw MyException("bind error!");
	if(!Socket::_listen(20))
		throw MyException("listen error!");
}
ServerSocket::~ServerSocket(){
	list<Socket*>::iterator iter;
	for(iter=clientSockets.begin();iter!=clientSockets.end();iter++)
		delete (*iter);
}

void ServerSocket::_accept(Socket& socket){
	if(!Socket::_accept(socket))
		throw MyException("accept error!");
}

//run server to connect multi-clients
void ServerSocket::run(){
	while(serviceFlag){
		if(clientSockets.size()>=20){
			serviceFlag=false;
		}
		else{
			serviceFlag=_accept();
		}
	}
}

//accept multi-clients
bool ServerSocket::_accept(){
	Socket* client =new Socket;
	_accept(*client);
	addClient(client);
	pthread_t newThread;
	int result=pthread_create(&newThread,NULL,processMessage,static_cast<void*>(client));
	if(result!=0){
		return false;
	}
}
void addClient(Socket* clientSocket);
static void deleteClient(Socket* clientSocket);
static void* processMessage(void* arg);
static void sendMsgToAllUsers(const std::string& message);

static list<Socket*> clientSockets;
static bool serviceFlag;
//use thread-read-write-lock to synchronize threads
static ThreadReadWriteLock readWriteLock;