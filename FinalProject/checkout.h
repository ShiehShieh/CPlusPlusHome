/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: checkout.h
 *description		: include the definition of checkout, which is used to
 *					  manage the checkout mode.
 */
#ifndef CHECKOUT
#define CHECKOUT

#include <string>
#include <iostream>
#include <sstream>
#include "payment.h"
#include "goods.h"

class Checkout
{
public:
	Checkout(): number(1){
		getline(std::cin, str);
		std::istringstream iss(str);
		iss >> commodity;
		if(iss >> number);
		find();
	}
	void find();
	~Checkout(){}

private:
	std::string str;
	int commodity;
	int number;
};

void Checkout::find(){
	for (std::vector<Good>::iterator i = allGoods.begin(); i != allGoods.end(); ++i)
	{
		if (i->returnCom() == commodity)
		{
			i->print();
		}
	}
}

/**
 * [dataInput input all the data from particular file which are in the 'sample' doucment.]
 */
void dataInput(){
	std::ifstream fisGood("//Users//huangli//Documents//C++homework//FinalProject//goods.txt");
	std::ifstream fisMember("//Users//huangli//Documents//C++homework//FinalProject//members.txt");
	std::ifstream fisShoppingCard("//Users//huangli//Documents//C++homework//FinalProject//shoppingcards.txt");
	Good good(fisGood);
//	std::cout << allGoods[0] << allGoods[1] << std::endl;
	Member member(fisMember);
//	std::cout << allMembers[0] << allMembers[1] << std::endl;
	ShoppingCard shoppingCard(fisShoppingCard);
//	std::cout << allShoppingCards[0] << allShoppingCards[1] << std::endl;
	fisGood.close();
	fisMember.close();
	fisShoppingCard.close();
}

#endif