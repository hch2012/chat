#include <iostream>
#include <string>
#include "service.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int i,j;
	Service service(8090);
	while(1){
		Socket client;
		service._accept(client);
		string message;
		service._recv(client,message);
		cout<<message<<endl;
		message="this is service";
		service._send(client,message);
	}
	return 0;
}