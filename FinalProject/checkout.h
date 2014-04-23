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
#include "payment.h"

class Checkout
{
public:
	Checkout(){}
	int enter(std::string str);
	~Checkout(){}

private:
};

int Checkout::enter(){
	return 5;
}

#endif