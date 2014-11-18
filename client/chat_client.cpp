#include "client.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string message="127.0.0.1";
	Client client(message,8090);
	client._send("this is client");
	client._recv(message);
	cout<<message<<endl;
	return 0;
}