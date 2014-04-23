/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: main.cpp
 *description		: Main file.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "member.h"
#include "goods.h"
#include "shoppingcard.h"
//#include "checkout.h"
//#include "payment.h"

int main(int argc, char const *argv[]){
	std::ifstream fisGood("//Users//huangli//Documents//C++homework//FinalProject//goods.text");
	std::ifstream fisMember("//Users//huangli//Documents//C++homework//FinalProject//members.text");
	std::ifstream fisShoppingCard("//Users//huangli//Documents//C++homework//FinalProject//shoppingcards.text");
	Good good(fisGood);
	std::cout << allGoods[0] << allGoods[1] << std::endl;
	Member member(fisMember);
	std::cout << allMembers[0] << allMembers[1] << std::endl;
	ShoppingCard shoppingCard(fisShoppingCard);
	std::cout << allShoppingCards[0] << allShoppingCards[1] << std::endl;
	return 0;
}
