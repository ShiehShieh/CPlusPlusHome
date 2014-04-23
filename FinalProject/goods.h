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
#include <vector>
#include <sstream>

class Good;
std::vector<Good> allGoods;
/**
 * Represent all the goods in the supermarket.
 */
class Good
{
public:
	Good(std::ifstream& is);
	Good(int comm, std::string na, std::string ori, int ben):
	commodity(comm), name(na), origin(ori), benchmark(ben){
		allGoods.push_back(*this);
	}
	void print();
	int returnCom(){
		return commodity;
	}
	~Good(){}

private:
	int commodity;
	std::string name;
	std::string origin;
	int benchmark;
};

Good::Good(std::ifstream& is){
	std::string strin, str;
	while(is >> strin){
		str += " " + strin;
	}

	/**
	 * [inString store all the input data.]
	 * @str [store the input data temporarily]
	 */
	std::istringstream inString(str);
	int commodity;
	std::string name;
	std::string origin;
	int benchmark;
	while(inString){
		inString >> commodity >> name >> origin >> benchmark;
		allGoods.push_back(Good(commodity, name, origin, benchmark));
	}
}

void Good::print(){
	std::cout << commodity << "\n" << name << "\n"
	<< origin << "\n" << benchmark << std::endl;
}

std::ostream& operator<<(std::ostream &os, Good& M){
	M.print();
	return os;
}

#endif