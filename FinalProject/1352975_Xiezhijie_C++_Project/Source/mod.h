/**
 * @file    : mod.h
 * @brief
 * @author  : 谢志杰Xie zhijie
 * @version : 1.0
 * @date    : 2014-05-06
 */

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
