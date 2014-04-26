#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "goods.h"

/**
 * read the file.
 */
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

/**
 * copy assignment operator.
 */
Goods& Goods::operator=(const Goods& other){
	this->commodity = other.commodity;
	this->name = other.name;
	this->origin = other.origin;
	this->benchmark = other.benchmark;
	this->count = other.count;
	this->discount = other.discount;
	return *this;
}

/**
 * output the goods to the command line.
 * @param os [description]
 */
void Goods::print(std::ostream &os) const{
	os << "commodity code: " << commodity << "\n"
	<< "name: " << name << "\n"
	<< "origin: " << origin << "\n"
	<< "benchmark: " << benchmark << "\n" << "count : "<< count << std::endl;
}
