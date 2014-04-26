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
	template<typename T> void update(std::vector<T> all, std::string file);
	//void deduction();
	bool cash();
	bool bankCard();
	bool shoppingCard();
	void cleanTheShoppingList();
	std::string info;
};

#endif