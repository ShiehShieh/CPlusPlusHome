/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: payment.h
 *description		: include the definition of payment, which is used
 *					  to manage the payment mode.
 */
#ifndef PAYMENT
#define PAYMENT

#include <iostream>
#include <string>

class Payment
{
public:
	Payment(){}
	void run(std::string command);
	void showList();
	~Payment(){}

private:
};

void Payment::run(std::string command){
}

void Payment::showList(){
}

#endif