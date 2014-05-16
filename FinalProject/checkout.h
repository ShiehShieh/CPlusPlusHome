#ifndef CHECKOUT
#define CHECKOUT

#include <fstream>
#include "goods.h"
#include "member.h"
#include "membership.h"
#include "shoppingcard.h"

class Checkout
{
	friend class Mod;
	friend class Payment;
	friend class Membership;
	static std::vector<Goods> goodsList;
public:
	Checkout():number(1){}
	int run();
	~Checkout(){}

private:
	int commodity;
	int number;
	Membership membership;

	void find();
	int interface(std::string &str, std::string &str1, std::string &str2, int status);
};

/**
 * [dataInput input all the data from particular file which are in the 'sample' doucment.]
 */
void dataInput(){
	std::ifstream fisGoods("goods.txt");
	std::ifstream fisMember("members.txt");
	std::ifstream fisShoppingCard("shoppingcards.txt");
	Goods goods(fisGoods);
//	std::cout << allGoods[0] << allGoods[1] << std::endl;
	Member member(fisMember);
//	std::cout << allMembers[0] << allMembers[1] << std::endl;
	ShoppingCard shoppingCard(fisShoppingCard);
//	std::cout << allShoppingCards[0] << allShoppingCards[1] << std::endl;
	fisGoods.close();
	fisMember.close();
	fisShoppingCard.close();
}

#endif