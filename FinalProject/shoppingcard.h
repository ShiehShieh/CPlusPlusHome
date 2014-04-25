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
	void print(std::ostream &os);
	std::string returnId(){
		return id;
	}
	double& returnBal(){
		return balance;
	}
	~ShoppingCard(){}

private:
	std::string id;
	double balance;
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
	double balance;
	while(inString){
		inString >> id >> balance;
		allShoppingCards.push_back(ShoppingCard(id, balance));
	}
	allShoppingCards.pop_back();
}

void ShoppingCard::print(std::ostream &os = std::cout){
	os << id << "\n" << balance << std::endl;
}

std::ostream& operator<<(std::ostream &os, ShoppingCard& M){
	M.print(os);
	return os;
}

#endif