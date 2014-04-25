/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: membership.h
 *description		: include the definition of membership which is 
 *					  used to manage the member information before
 *					  checkout module.
 */
#include <iostream>
#include <string>
#include "goods.h"
#include "checkout.h"
#include "myerror.h"
#include "member.h"
#include "membership.h"

void Membership::deduction(){
	bill = 0;
	for (std::vector<Goods>::iterator i = Checkout::goodsList.begin(); i != Checkout::goodsList.end(); ++i){
		bill += i->returnBenchmark() * i->returnCount() * i->returnDiscount();
	}
}

void Membership::run(){
	int mark = 0;
	std::string command = "go";
	int number;
	bill = 0;
	std::cout << "-----MEMBERSHIP MODULE-----\n"
	<< "command : " << std::flush;
	std::cin >> command;
	if(command == "quit"){
		return;
	}
	std::cout << "Please enter your member number : " << std::flush;
	std::cin >> number;
	while(command != "quit" && command == "go"){
		for (std::vector<Member>::iterator i = allMembers.begin(); i != allMembers.end(); ++i){
			try{
				if(i->returnNumber() == number){
					mark = 1;
					level = i->returnLevel();
					i->print();
					return;
				}
				if(i == allMembers.end() - 1 && mark != 1){
					throw Myerror("-----Illegal Number.");
				}
			}catch(Myerror error){
				std::cout << "-----Membership error handler-----\n"
				<< error.what() << "Please try again." << std::endl;
			}
		}
		std::cout << "-----MEMBERSHIP MODULE-----\n"
		<< "command : " << std::flush;
		std::cin >> command;
		if(command == "quit"){
			return;
		}
		std::cout << "Please enter your member number : " << std::flush;
		std::cin >> number;
	}
	return;
}

int Membership::discount(){
	switch(level){
		case 5:{
			for (std::vector<Goods>::iterator i = Checkout::goodsList.begin(); i != Checkout::goodsList.end(); ++i){
				double returnBenchmark = i->returnBenchmark();
				if(returnBenchmark < 10){
					i->setDiscount(1);
				}else if(returnBenchmark < 20){
					i->setDiscount(0.95);
				}else{
					i->setDiscount(0.90);
				}
			}
			return 1;
		}break;
		case 4:{
			deduction();
			if(bill < 1000){
				bill *= 0.95;
			}else if(bill < 2000){
				bill = 950 + (bill - 1000) * 0.90;
			}else{
				bill = 950 + 900 + (bill - 2000) * 0.85;
			}
			return bill;
		}break;
		case 3:{
			deduction();
			if(bill < 2000){
				/*
				 *Do nothing.
				 */
			}else if(bill < 5000){
				bill = 2000 + (bill - 2000) * 0.95;
			}else{
				bill = 2000 + 2850 + (bill - 5000) * 0.90;
			}
			return bill;
		}break;
		case 2:{
			deduction();
			return bill;
		}break;
	}
	return 0;
}

void Membership::addPoint(){
	return;
}

void Membership::upgrade(){
	return;
}
