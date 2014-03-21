#include <iostream>
#include "TEXT.h"

int main(int argc, char const *argv[]){
	typedef Text Threething;
	typedef Textstruct RealStruct;
//用类类型
	Threething threething("a", "b", 5);
	Threething some("c", "d", 55555);
	Text *pText = &threething;

	std::cout << "A class" << std::endl;
	std::cout << threething;
	*pText = some;
	std::cout << *pText << std::endl;
//用结构体（有构造器）
	RealStruct realstruct{"a", "b", 5};
	RealStruct *pStruct = &realstruct;

	std::cout << "A struct" << std::endl;
	std::cout << realstruct.str1 << " " << realstruct.str2 << " " << realstruct.i << std::endl;
	pStruct->str1 = "c";
	pStruct->str2 = "d";
	pStruct->i 	  = 55;
	std::cout << pStruct->str1 << " " << pStruct->str2 << " " << pStruct->i << std::endl;

	return 0;
}