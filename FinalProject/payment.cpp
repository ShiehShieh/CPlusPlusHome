/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: payment.h
 *description		: include the definition of payment, which is used
 *					  to manage the payment mode.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
#include "goods.h"
#include "checkout.h"
#include "shoppingcard.h"
#include "membership.h"
#include "payment.h"
#include "myerror.h"

//extern std::vector<Goods> goodsList;

std::ostringstream myStringStream("-----PAYMENT INFORMATION-----\n", std::ios_base::ate);

/*
void Payment::deduction(){
	for (std::vector<Goods>::iterator i = Checkout::goodsList.begin(); i != Checkout::goodsList.end(); ++i){
		bill += i->returnBenchmark() * i->returnCount();
	}
}
*/

/**
 * payment approach : cash.
 */
void Payment::cash(){
	std::cout << bill << std::endl;
	int money = 0;

	/**
	 * return to mod when bill is reduced to zero.
	 */
	if(bill == 0){
		std::cout << "-----Transaction has already been done."
		<< std::endl;
		myStringStream << "-----Transaction has already been done." << std::endl;
		return;
	}

	std::cout << "-----Payment approach : cash-----\n"
	<< "The number of cash : " << std::flush;
	myStringStream << "-----Payment approach : cash-----\n"
	<< "The number of cash : " << std::flush;
	std::cin >> money;

	/**
	 * make the deduction here.
	 */
	bill -= money;

	std::cout << "-----The money needed : "<< bill << std::endl;
	myStringStream << "-----The money needed : "<< bill << std::endl;
}

/**
 * payment approach ; bank card.
 */
void Payment::bankCard(){
	std::string bankCardNumber;
	std::string name;
	double amount = 0;

	/**
	 * return to mod when bill is reduced to zero.
	 */
	if(bill == 0){
		std::cout << "-----Transaction has already been done."
		<< std::endl;
		myStringStream << "-----Transaction has already been done."
		<< std::endl;
		return;
	}

	std::cout << "-----Payment approach : bank card-----\n"
	<< "The number of bank card : " << std::flush;
	myStringStream << "-----Payment approach : bank card-----\n"
	<< "The number of bank card : " << std::flush;
	std::cin >> bankCardNumber;
	std::cout << "Comsumer's name : " << std::flush;
	myStringStream << "Comsumer's name : " << std::flush;
	std::cin >> name;
	std::cout << "The amount of consumption : " << std::flush;
	myStringStream << "The amount of consumption : " << std::flush;
	std::cin >> amount;

	/**
	 * Make the deduction here.
	 */
	bill -= amount;

	std::cout << "The money needed : "<< bill << std::endl;
	myStringStream << "The money needed : "<< bill << std::endl;
}

void Payment::shoppingCard(){
	std::string id;
	double amount = 0;
	int mark = 0;

	/**
	 * return to mod when bill is reduced to zero.
	 */
	if(bill == 0){
		std::cout << "-----Transaction has already been done."
		<< std::endl;
		myStringStream << "-----Transaction has already been done."
		<< std::endl;
		return;
	}

	std::cout << "-----Payment approach : shopping gift card-----\n"
	<< "The id of the shopping gift card : " << std::flush;
	myStringStream << "-----Payment approach : shopping gift card-----\n"
	<< "The id of the shopping gift card : " << std::flush;
	std::cin >> id;
	std::cout << "-----the amout of consumption : " << std::flush;
	myStringStream << "-----the amout of consumption : " << std::flush;
	std::cin >> amount;
/*	for (std::vector<ShoppingCard>::iterator i = allShoppingCards.begin(); i != allShoppingCards.end(); ++i)
	{
		i->print();
 	}*/
	/**
	 * find the shopping card and comfirm the
	 * balance before settle the account.
	 */
	for (std::vector<ShoppingCard>::iterator i = allShoppingCards.begin(); i != allShoppingCards.end(); ++i){
		try{
			if(i->returnId() == id){
				mark = 1;
				if(i->returnBal() > amount){
					i->returnBal() -= amount;
					bill -= amount;
					std::cout << "-----The money remained in the shopping card : "<< i->returnBal() << std::endl;
					std::cout << "-----The money needed : "<< bill << std::endl;
					myStringStream << "-----The money remained in the shopping card : "<< i->returnBal() << std::endl;
					myStringStream << "-----The money needed : "<< bill << std::endl;
				}else{
					throw Myerror("The balance is not enough.");
				}
			}
			if(i == allShoppingCards.end() - 1 && mark != 1){
				throw Myerror("-----Illegal id.");
			}
		}catch(Myerror error){
			std::cout << "-----Payment error handler-----\n"
			<< error.what() << std::endl;
			myStringStream << "-----Payment error handler-----\n"
			<< error.what() << std::endl;
		}
	}

	/**
	 * update the shoppingcards.txt
	 */
	update(allShoppingCards, "newshoppingcardfile.txt");
}

/**
 * manage the payment module.
 * @param M [description]
 */
void Payment::run(Membership M){
	double status = 0;
	std::string command;

	/**
	 * status = gross price.
	 */
	status = M.discount();

	/**
	 * discounted price.
	 */
	bill = M.returnBill(status);

	/**
	 * upgrade the member point.
	 */
	M.addPoint();
	M.upgrade();

	std::cout << "-----Payment module-----\n"
	<< "command : " << std::flush;
	myStringStream << "-----Payment module-----\n"
	<< "command : " << std::flush;
	std::cin >> command;

	/**
	 * select the payment approach here.
	 */
	while(command != "quit"){
		if(command == "cash"){
			cash();
		}else if(command == "bank"){
			bankCard();
		}else if(command == "shop"){
			shoppingCard();
		}
		std::cout << "-----Payment module-----\n"
		<< "command : " << std::flush;
		myStringStream << "-----Payment module-----\n"
		<< "command : " << std::flush;
		std::cin >> command;
	}

	/**
	 * output the shopping list to the command list.
	 */
	showList();

	/**
	 * clean the shopping list.
	 */
	cleanTheShoppingList();

	return;

}

template<typename T>
void Payment::update(std::vector<T> all, std::string file){
	std::string command;
	std::cout << "-----UPDATE CHECK MODULE-----\n"
	<< "-----you data will be changed, please select a mod : \n"
	<< "NEW : creat a new file .\nATE : append to the old file .\n"
	<< "command : " << std::flush;

	try{
		std::cin >> command;
		if(command == "new"){
			std::ofstream newFile("//Users//huangli//Documents//C++homework//FinalProject//" + file, std::ios_base::out);
			for (auto i = all.begin(); i != all.end(); ++i){
				newFile << *i << std::flush;
			}
		}else if(command == "ate"){
			std::ofstream oldFile("//Users//huangli//Documents//C++homework//FinalProject//" + file, std::ios_base::out);
			for (auto i = all.begin(); i != all.end(); ++i){
				oldFile << *i << std::flush;
			}
		}else{
			throw Myerror("-----The command does exit.");
		}
	}catch(Myerror error){
		std::cout << error.what() << std::endl;
	}

	return;

}

/**
 * clean the shopping list before last transaction.
 */
void Payment::cleanTheShoppingList(){

	Checkout::goodsList.clear();

}

/**
 * output the shopping list to the command list.
 */
void Payment::showList(){
	std::ofstream of("//Users//huangli//Documents//C++homework//FinalProject//paymentOutput.txt", std::ofstream::out);
	of << "-----SHOPPING LIST-----" << std::endl;
	for (std::vector<Goods>::iterator i = Checkout::goodsList.begin(); i != Checkout::goodsList.end(); ++i){
		of << *i << std::flush;
		std::cout << *i << std::flush;
	}
	of << myStringStream.str() << std::endl;
	of.close();
}
