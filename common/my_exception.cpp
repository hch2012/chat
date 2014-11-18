#include "my_exception.h"

MyException::MyException(){

}
MyException::MyException(std::string &mesg){
	this->error_message=mesg;
}
MyException::~MyException(){

}
std::string MyException::description(){
	return this->error_message;
}