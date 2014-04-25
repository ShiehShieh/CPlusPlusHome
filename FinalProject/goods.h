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

class Goods;
std::vector<Goods> allGoods;
/**
 * Represent all the goods in the supermarket.
 */
class Goods
{
public:
	Goods(std::ifstream& is);
	Goods(int comm, std::string na, std::string ori, int ben):
	commodity(comm), name(na), origin(ori), benchmark(ben), count(1), discount(1){}
	void print(std::ostream &os);
	Goods(const Goods& other){
		*this = other;
	}
	Goods& operator=(const Goods& other);
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
	int returnCount(){
		return count;
	}
	double returnDiscount(){
		return discount;
	}
	void setDiscount(int discounts){
		discount = discounts;
	}
	void setCount(int counts){
		count = counts;
	}
	~Goods(){}

private:
	int commodity;
	std::string name;
	std::string origin;
	int benchmark;
	int count;
	double discount;
};

Goods::Goods(std::ifstream& is):count(1), discount(1){
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
		allGoods.push_back(Goods(commodity, name, origin, benchmark));
	}
	allGoods.pop_back();
}

Goods& Goods::operator=(const Goods& other){
	this->commodity = other.commodity;
	this->name = other.name;
	this->origin = other.origin;
	this->benchmark = other.benchmark;
	this->count = other.count;
	this->discount = other.discount;
	return *this;
}

void Goods::print(std::ostream &os = std::cout){
	os << "commodity code: " << commodity << "\n"
	<< "name: " << name << "\n"
	<< "origin: " << origin << "\n"
	<< "benchmark: " << benchmark << "\n" << "count : "<< count << std::endl;
}

std::ostream& operator<<(std::ostream &os, Goods& M){
	M.print(os);
	return os;
}

#endif