#ifndef MOD
#define MOD

#include <iostream>
#include <string>
#include "checkout.h"
#include "payment.h"

class Mod
{
public:
	Mod(){}
	void run();
	~Mod(){}

private:
	Checkout checkout;
	Payment payment;
};

#endif