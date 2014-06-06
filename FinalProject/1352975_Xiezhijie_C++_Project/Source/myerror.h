/**
 * student number : 1352975
 * name           : 谢志杰Xie zhijie
 *file name       : myerror.h
 *description     : include the definition of my error handler class
 */
#ifndef MYERROR
#define MYERROR

#include <stdexcept>
#include <string>

class Myerror : public std::runtime_error{
public:
	Myerror(const std::string str):std::runtime_error(str){}
//	~Myerror(){}
};

#endif
