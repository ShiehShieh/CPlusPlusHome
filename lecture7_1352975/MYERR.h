#ifndef MYERR
#define MYERR

#include <stdexcept>
#include <exception>

class MyErr: public std::runtime_error{
public:
	MyErr(const char *c):std::runtime_error(c){}
	~MyErr(){}

private:
};

class getting_from_empty: public std::runtime_error
{
public:
	getting_from_empty(const char *c):std::runtime_error(c){}
	~getting_from_empty(){}

};

class filling_to_full: public std::runtime_error
{
public:
	filling_to_full(const char* c):std::runtime_error(c){}
	~filling_to_full(){}

};

#endif