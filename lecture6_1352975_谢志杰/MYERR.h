#ifndef MYERR
#define MYERR

#include <stdexcept>

class MyErr: public std::runtime_error{
public:
	MyErr(const char *c):std::runtime_error(c){}
	~MyErr(){}

private:
};

#endif