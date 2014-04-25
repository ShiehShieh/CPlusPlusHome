/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: membership.h
 *description		: include the definition of membership which is 
 *					  used to manage the member information before
 *					  checkout module.
 */
#ifndef MEMBERSHIP
#define MEMBERSHIP

#include <iostream>
#include <string>
#include "goods.h"
#include "checkout.h"
#include "myerror.h"
#include "member.h"

class Membership
{
public:
	Membership(){}
	void run();
	~Membership(){}

private:
	int level;
	void discount();
	void addPoint();
	void upgrade();
};

void Membership::run(){
	int mark = 0;
	std::string command = "go";
	int number;
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
				}
				if(i == allMembers.end() - 1 && mark != 1){
					throw Myerror("-----Illegal Number.");
				}
			}catch(Myerror error){
				std::cout << "-----Membership error handler-----\n"
				<< error.what() << "Please try again." << std::endl;
			}
		}
		std::cout << "command : " << std::flush;
		std::cin >> command;
		if(command == "quit"){
			return;
		}
		std::cout << "Please enter your member number : " << std::flush;
		std::cin >> number;
	}
	return;
}

void Membership::discount(){
	switch(level){
		case 5:{
			for (std::vector<Goods>::iterator i = goodsList.begin(); i != goodsList.end(); ++i){
				double returnBenchmark = i->returnBenchmark();
				if(returnBenchmark < 10){
					i->setDiscount(1);
				}else if(returnBenchmark < 20){
					i->setDiscount(0.95);
				}else{
					i->setDiscount(0.90);
				}
			}
		}break;
		case 4:break;
		case 3:break;
		case 2:break;
	}
	return;
}

void Membership::addPoint(){
	return;
}

void Membership::upgrade(){
	return;
}

#endif