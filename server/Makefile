chatService: chatService.o service.o socket.o 
	g++ -g -o chatService chatService.o service.o socket.o 
chatService.o: chatService.cpp
	g++ -g -c -o chatService.o chatService.cpp
service.o:service.cpp 
	g++ -g -c -o service.o service.cpp
socket.o:socket.cpp
	g++ -g -c -o socket.o socket.cpp