#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "shoppingcard.h"

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
void ShoppingCard::print(std::ostream &os) const{
	os << id << "\n" << balance << std::endl;
}
