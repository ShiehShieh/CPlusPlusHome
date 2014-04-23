/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: shoppingcard.h
 *description		: include the definition of shoppingcard
 */
#ifndef SHOPPINGCARD
#define SHOPPINGCARD

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class ShoppingCard;
std::vector<ShoppingCard> allShoppingCards;

class ShoppingCard
{
public:
	ShoppingCard(std::ifstream &is);
	ShoppingCard(std::string i, int bal):id(i), balance(bal){}
	void print();
	~ShoppingCard(){}

private:
	std::string id;
	int balance;
};

ShoppingCard::ShoppingCard(std::ifstream& is){
	std::string strin, str;
	while(is >> strin){
		str += " " + strin;
	}

	/**
	 * [inString store all the input data.]
	 * @str [store the input data temporarily]
	 */
	std::istringstream inString(str);
	std::string id;
	int balance;
	while(inString){
		inString >> id >> balance;
		allShoppingCards.push_back(ShoppingCard(id, balance));
	}
}

void ShoppingCard::print(){
	std::cout << id << "\n" << balance << std::endl;
}

std::ostream& operator<<(std::ostream &os, ShoppingCard& M){
	M.print();
	return os;
}

#endif