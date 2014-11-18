#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <string>
class MyException
{
public:
	MyException();
	MyException(std::string &mesg);
	virtual ~MyException();
	std::string description();
private:
	int error_message;
};



#endif