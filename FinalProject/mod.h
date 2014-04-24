/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: mod.h
 *description		: include the definition of system operator
 */
#ifndef MOD
#define MOD

#include <iostream>
#include <string>
#include "checkout.h"
#include "payment.h"
#include "myerror.h"

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

void Mod::help(){
	std::cout << "----------------------------------------\n"
	<< "command 		function 		\n"
	<< "checkout 	switch to checkout module\n"
	<< "payment 	switch to payment module\n"
	<< "----------------------------------------" << std::endl;
}

void Mod::run(){
	std::string command;
	std::cout << "command : " << std::flush;
	std::cin >> command;
	while(command != "quit"){
		try{
			if(command == "checkout"){
				checkout.run();
			}else if(command == "payment"){
				std::cin >> command;
				payment.run(command);
			}else{
				throw Myerror("command does exit, please try again.");
			}
		}catch(Myerror error){
			std::cout << error.what() << std::endl;
			help();
		}
		std::cout << "command : " << std::flush;
		std::cin >> command;

	}
}

#endif
