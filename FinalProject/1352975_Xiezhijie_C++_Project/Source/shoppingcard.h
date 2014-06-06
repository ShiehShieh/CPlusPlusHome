/**
 * student number : 1352975
 * name           : 谢志杰Xie zhijie
 *file name       : shoppingcard.h
 *description     : include the definition of shoppingcard
 */
#ifndef SHOPPINGCARD
#define SHOPPINGCARD

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

/**
 * forward declaration
 */
class ShoppingCard;
std::map<std::string, ShoppingCard*> allShoppingCards;
std::vector<ShoppingCard> allShoppingCardss;

class ShoppingCard
{
public:
	ShoppingCard(std::ifstream &is);
	ShoppingCard(std::string i, int bal):id(i), balance(bal){}
	void print(std::ostream &os = std::cout) const;
	void fprint(std::ostream &os) const;

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
 * work with 'print()'.
 */
std::ostream& operator<<(std::ostream &os, const ShoppingCard& M){
	M.print(os);
	return os;
}

#endif
