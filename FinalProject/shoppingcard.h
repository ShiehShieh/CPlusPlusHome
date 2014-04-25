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

/**
 * forward declaration
 */
class ShoppingCard;
std::vector<ShoppingCard> allShoppingCards;

class ShoppingCard
{
public:
	ShoppingCard(std::ifstream &is);
	ShoppingCard(std::string i, int bal):id(i), balance(bal){}
	void print(std::ostream &os);

	/**
	 * return the id.
	 * @return [description]
	 */
	std::string returnId(){
		return id;
	}

	/**
	 * return the remaining balance.
	 * @return [description]
	 */
	double& returnBal(){
		return balance;
	}
	~ShoppingCard(){}

private:
	std::string id;
	double balance;
};

/**
 * initialize the shoppingcard by a ifstream.
 */
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

/**
 * output the shoppingcard to the command list.
 * @param os [description]
 */
void ShoppingCard::print(std::ostream &os = std::cout){
	os << id << "\n" << balance << std::endl;
}

/**
 * work with 'print()'.
 */
std::ostream& operator<<(std::ostream &os, ShoppingCard& M){
	M.print(os);
	return os;
}

#endif