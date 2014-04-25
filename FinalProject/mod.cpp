/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: mod.h
 *description		: include the definition of system operator
 */
#include <iostream>
#include <string>
#include "checkout.h"
#include "payment.h"
#include "myerror.h"
#include "mod.h"

void Mod::help(){
	std::cout << "----------------------------------------\n"
	<< "command 		function 		\n"
	<< "checkout 	switch to checkout module\n"
	<< "payment 	switch to payment module\n"
	<< "----------------------------------------" << std::endl;
}

void Mod::run(){
	int status = 0;
	std::string command;
	std::cout << "-----system-----\n"
	<< "command : " << std::flush;
	std::cin >> command;
	while(command != "quit"){
		try{
			if(command == "checkout"){
				status = checkout.run();
			}else if(command == "payment"){
				payment.run(checkout.membership);
			}else{
				throw Myerror("command does exit, please try again.");
			}
			if (status != 0){
				payment.run(checkout.membership);
			}
		}catch(Myerror error){
			std::cout << error.what() << std::endl;
			help();
		}
		std::cout << "-----system-----\n"
		<< "command : " << std::flush;
		std::cin >> command;

	}
}
