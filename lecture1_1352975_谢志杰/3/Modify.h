#ifndef MODIFY
#define MODIFY

#include <string>

void modify(std::string *str)
{
	*str += " world.";
}

void modify(std::string &str)
{
	str += "Hello everyone.";
}

#endif