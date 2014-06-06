/**
 * @file    : payment.h
 * @brief
 * @author  : 谢志杰Xie zhijie
 * @version : 1.0
 * @date    : 2014-05-06
 */

#ifndef PAYMENT
#define PAYMENT

#include <vector>
#include <string>
#include "membership.h"

class Payment
{
public:
	Payment(){}
	void run(Membership M);
	void showList();
	~Payment(){}

private:
	double bill;
	Membership membership;
	template<typename T, typename W> void update(std::map<T, W> all, std::string file, int status = 0);
	//void deduction();
	bool cash();
	bool bankCard();
	bool shoppingCard();
	void cleanTheShoppingList();
	std::string info;
};

#endif
