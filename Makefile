all: chatClient chatService

chatClient: chatClient.o client.o socket.o 
	g++ -g -o chatClient chatClient.o client.o socket.o 
chatClient.o: client/chatClient.cpp
	g++ -g -c -o chatClient.o client/chatClient.cpp
client.o:client/client.cpp 
	g++ -g -c -o client.o client/client.cpp
socket.o:common/socket.cpp
	g++ -g -c -o socket.o common/socket.cpp


chatService: chatService.o service.o socket.o 
	g++ -g -o chatService chatService.o service.o socket.o 
chatService.o: server/chatService.cpp
	g++ -g -c -o chatService.o server/chatService.cpp
service.o:server/service.cpp 
	g++ -g -c -o service.o server/service.cpp
