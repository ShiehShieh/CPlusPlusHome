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

class ShoppingCard
{
public:
	ShoppingCard(int i, int bal):id(i), balance(bal){}
	void print();
	~ShoppingCard(){}

private:
	int id;
	int balance;
};

void ShoppingCard::print(){
	std::cout << id << "\n" << name << std::endl;
}

std::ostream& operator<<(std::ostream &os, ShoppingCard& M) const{
	M.print();
	return os
}

#endif