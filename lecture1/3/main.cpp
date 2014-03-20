#include <iostream>
#include <string>
#include "Modify.h"

int main(int argc, char const *argv[])
{
	std::string str1("Hello!");
	std::string str2;

	modify(&str1);
	std::cout << str1 << std::endl;
	modify(str1);
	std::cout << str1 << std::endl;

	return 0;
}