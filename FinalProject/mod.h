#ifndef MOD
#define MOD

#include "checkout.h"
#include "payment.h"

/**
 * the definition of class Mod.
 */
class Mod
{
public:
	Mod(){}
	void run();
	~Mod(){}

private:
	Checkout checkout;
	Payment payment;
	void help();
};

#endif