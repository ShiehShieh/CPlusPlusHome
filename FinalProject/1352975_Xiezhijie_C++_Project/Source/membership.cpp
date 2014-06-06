/**
 * student number : 1352975
 * name           : 谢志杰Xie zhijie
 *file name       : membership.h
 *description     : include the definition of membership which is
 *			  used to manage the member information before
 *			  checkout module.
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

	/**
	 * the user interface.
	 */
	std::cout << "\033[;34;1m \n-----MEMBERSHIP MODULE-----\n\033[0m"
	<< "\033[;36;1m command(type 'quit' to quit) : \033[0m" << std::flush;
	std::cin >> command;
	if(command == "quit"){

		/**
		 * treat as a non-member.
		 */
		level = 2;

		return;
	}
	std::cout << "\033[;36;1m Please enter your member number : \033[0m" << std::flush;
	std::cin >> number;

	while(command != "quit"){
		auto i = allMembers.find(number);
		try{
			if(i != allMembers.end()){
				mark = 1;
				memberSize = i;
				level = i->second->returnLevel();
				i->second->print();

				return;

			}
			if(i == allMembers.end()){
				throw Myerror("\033[;31;1m -----Illegal Number.\033[0m");
			}
		}catch(Myerror error){
			std::cout << "\033[;34;1m -----Membership error handler-----\n\033[0m"
			<< error.what() << "\033[;34;1m Please try again.\033[0m" << std::endl;
		}

		/**
		 * the user interface.
		 */
		std::cout << "\033[;34;1m -----MEMBERSHIP MODULE-----\n\033[0m"
		<< "\033[;36;1m command : \033[0m" << std::flush;
		std::cin >> command;

		if(command == "quit"){
			return;
		}

		std::cout << "\033[;36;1m Please enter your member number : \033[0m" << std::flush;
		std::cin >> number;
	}

	return;

}

double Membership::discount(){
	switch(level){
		/**
		 * gold
		 */
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
		/**
		 * silver
		 */
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

		/**
		 * regular
		 */
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

		/**
		 * non-member
		 */
		case 2:{
			deduction();

			return bill;

		}break;

	}

	return 0;

}



void Membership::addPoint(){
	double point = 0;
	auto pMember = memberSize->second;

	/**
	 * the user interface.
	 */
	std::cout << "\033[;34;1m -----member point added.\033[0m" << std::endl;

	switch(level){
		case 5:{
			if(bill < 1000){
				point *= bill * 1.5;
			}else if(bill < 5000){
				point = 1500 + (bill - 5000) * 1.8;
			}else{
				point = 1500 + 7200 + (bill - 5000) * 2;
			}

			pMember->addPoint(point);
			pMember->print();
		}break;
		case 4:{
			if(bill < 2000){
				point *= bill * 1.2;
			}else if(bill < 5000){
				point = 2400 + (bill - 2000) * 1.5;
			}else{
				point = 2400 + 4500 + (bill - 5000) * 1.8;
			}

			pMember->addPoint(point);
			pMember->print();

		}break;
		case 3:{
			pMember->addPoint(bill * 0.5);
			pMember->print();

		}break;
		case 2:{

			/**
			 * Do nothing.
			 */
		}break;
	}

	return;

}

/**
 * upgrade the member's level with respect to their point.
 */
void Membership::upgrade(){
	auto pMember = memberSize->second;
	int point = pMember->returnPoint();

	if(point > 10000 && point < 50000){
		pMember->setLevel(4);
	}else if(point > 5000){
		pMember->setLevel(5);
	}

	return;

}
