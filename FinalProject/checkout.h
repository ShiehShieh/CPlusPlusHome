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
#include <vector>
#include "goods.h"
#include "membership.h"

class Checkout
{
	friend class Payment;
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
};

//std::vector<Goods> goodsList;
std::vector<Goods> Checkout::goodsList;

int Checkout::run(){
	membership.run();
	//getline();
	std::string str, str1, str2;
	std::cout << "-----Checkout module.-----\n"
	<< "command/commodity : " << std::flush;
	std::cin >> str1;
	if (str1 == "quit"){
		return 5;
	}
	std::cout << "number : (pass 'p' to skip)" << std::flush;
	std::cin >> str2;
	if (str2 != "p"){
		str = str1 + " " + str2;
	}else{
		str = str1 + " 1";
	}
	while(str1 != "quit"){
		std::istringstream iss(str);
		iss >> commodity;
		if(iss >> number){}
		find();
		std::cout << "-----Checkout module.-----\n"
		<< "command/commodity : " << std::flush;
		std::cin >> str1;
		if (str1 == "quit"){
			return 5;
		}
		std::cout << "number : (pass 'p' to skip)" << std::flush;
		std::cin >> str2;
		if (str2 != "p"){
			str = str1 + " " + str2;
		}else{
			str = str1 + " 1";
		}
	}
	return 5;
}

/**
 * Find the correct purchase.
 */
void Checkout::find(){
	for (std::vector<Goods>::iterator i = allGoods.begin(); i != allGoods.end(); ++i)
	{
		if (i->returnCom() == commodity)
		{
			int total = i->returnBenchmark() * number * i->returnDiscount();
			i->print();
			std::cout << "total: " << total << std::endl;
			goodsList.push_back(Goods(*i));
			goodsList.back().setCount(number);
			std::cout << "count: " << number << std::endl;
		}
	}
}

/**
 * [dataInput input all the data from particular file which are in the 'sample' doucment.]
 */
void dataInput(){
	std::ifstream fisGoods("//Users//huangli//Documents//C++homework//FinalProject//goods.txt");
	std::ifstream fisMember("//Users//huangli//Documents//C++homework//FinalProject//members.txt");
	std::ifstream fisShoppingCard("//Users//huangli//Documents//C++homework//FinalProject//shoppingcards.txt");
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