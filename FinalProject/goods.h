/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: goods.h
 *description		: include the definition of good
 */
#ifndef GOODS
#define GOODS

#include <iostream>
#include <string>
 #include <fstream>

class Good
{
public:
	Good(std::fostream& os);
	Good(int comm, std::string na, std::string ori, int ben):
	commodity(comm), name(na), origin(ori), benchmark(ben){}
	~Good(){}

private:
	int commodity;
	std::string name;
	str::string origin;
	int benchmark;
};

void Good::print(){
	std::cout << commodity << "\n" << name << "\n"
	<< origin << "\n" << benchmark << std::endl;
}

std::ostream& operator<<(std::ostream &os, Good& M) const{
	M.print();
	return os
}

#endif