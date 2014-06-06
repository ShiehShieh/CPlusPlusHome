/**
 * @file          : goods.cpp
 * @brief
 * student number : 1352975
 * name           : 谢志杰Xie zhijie
 * @version       : 1.0
 * @date          : 2014-05-06
 */

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
		auto var = new Goods(commodity, name, origin, benchmark);
		allGoods.insert(std::make_pair(commodity, var));
	}
//	allGoods.pop_back();
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
	os << "\033[;33;1m commodity code: \033[0m" << commodity << "\n"
	<< "\033[;33;1m name: \033[0m" << name << "\n"
	<< "\033[;33;1m origin: \033[0m" << origin << "\n"
	<< "\033[;33;1m benchmark: \033[0m" << benchmark << "\n" << "count : "<< count << std::endl;
}

