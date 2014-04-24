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
	commodity(comm), name(na), origin(ori), benchmark(ben), count(1){}
	void print();
	Good(const Good& other){
		*this = other;
	}
	Good& operator=(const Good& other);
	int returnCom(){
		return commodity;
	}
/*	std::string returnName(){
		return name;
	}
	std::string returnOrigin(){
		return origin;
	}
*/	int returnBenchmark(){
		return benchmark;
	}
	void setCount(int counts){
		count = counts;
	}
	~Good(){}

private:
	int commodity;
	std::string name;
	std::string origin;
	int benchmark;
	int count;
};

Good::Good(std::ifstream& is):count(1){
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

Good& Good::operator=(const Good& other){
	this->commodity = other.commodity;
	this->name = other.name;
	this->origin = other.origin;
	this->benchmark = other.benchmark;
	this->count = other.count;
	return *this;
}

void Good::print(){
	std::cout << "commodity code: " << commodity << "\n"
	<< "name: " << name << "\n"
	<< "origin: " << origin << "\n"
	<< "benchmark: " << benchmark << std::endl;
}

std::ostream& operator<<(std::ostream &os, Good& M){
	M.print();
	return os;
}

#endif