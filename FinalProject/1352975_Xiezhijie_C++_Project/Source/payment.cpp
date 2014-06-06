/**
 * student number : 1352975
 * name           : 谢志杰Xie zhijie
 *file name       : payment.h
 *description     : include the definition of payment, which is used
 *			  to manage the payment mode.
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
bool Payment::cash(){
	int money = 0;

	/**
	 * return to mod when bill is reduced to zero.
	 */
	std::cout << "\033[;34;1m The momey needed to pay : \033[0m"
	<< bill << std::endl;
	if(bill == 0){
		std::cout << "\033[;34;1m -----Transaction has already been done.\033[0m"
		<< std::endl;
		myStringStream << "-----Transaction has already been done." << std::endl;

		return true;

	}

	/**
	 * the user interface.
	 */
	std::cout << "\033[;34;1m \n-----Payment approach : cash-----\n\033[0m"
	<< "\033[;34;1m The number of cash : \033[0m" << std::flush;
	myStringStream << "\n-----Payment approach : cash-----\n"
	<< "The number of cash : " << std::flush;
	std::cin >> money;
	myStringStream << money << std::endl;

	/**
	 * make the deduction here.
	 */
	bill -= money;

	std::cout << "\033[;34;1m -----The money needed : \033[0m"<< bill << std::endl;
	myStringStream << "-----The money needed : "<< bill << std::endl;

	return false;

}

/**
 * payment approach ; bank card.
 */
bool Payment::bankCard(){
	std::string bankCardNumber;
	std::string name;
	double amount = 0;

	/**
	 * return to mod when bill is reduced to zero.
	 */
	if(bill == 0){
		std::cout << "\033[;34;1m -----Transaction has already been done.\033[0m"
		<< std::endl;
		myStringStream << "-----Transaction has already been done."
		<< std::endl;

		return true;

	}

	/**
	 * The user interface.
	 */
	std::cout << "\033[;34;1m \n-----Payment approach : bank card-----\n\033[0m"
	<< "\033[;36;1m The number of bank card : \033[0m" << std::flush;
	myStringStream << "\n-----Payment approach : bank card-----\n"
	<< "The number of bank card : " << std::flush;
	std::cin >> bankCardNumber;
	myStringStream << bankCardNumber << std::endl;
	std::cout << "\033[;36;1m Comsumer's name : \033[0m" << std::flush;
	myStringStream << "Comsumer's name : " << std::flush;
	std::cin >> name;
	myStringStream << name << std::endl;
	std::cout << "\033[;36;1m The amount of consumption : \033[0m" << std::flush;
	myStringStream << "The amount of consumption : " << std::flush;
	std::cin >> amount;
	myStringStream << amount << std::endl;

	/**
	 * Make the deduction here.
	 */
	bill -= amount;

	std::cout << "\033[;34;1m The money needed : \033[0m"<< bill << std::endl;
	myStringStream << "The money needed : "<< bill << std::endl;

	return false;

}

bool Payment::shoppingCard(){
	std::string id;
	double amount = 0;
	int mark = 0;

	/**
	 * return to mod when bill is reduced to zero.
	 */
	if(bill == 0){
		std::cout << "\033[;34;1m -----Transaction has already been done.\033[0m"
		<< std::endl;
		myStringStream << "-----Transaction has already been done."
		<< std::endl;

		return true;

	}

	/**
	 * The user interface.
	 */
	std::cout << "\033[;34;1m \n-----Payment approach : shopping gift card-----\n\033[0m"
	<< "\033[;36;1m The id of the shopping gift card : \033[0m" << std::flush;
	myStringStream << "\n-----Payment approach : shopping gift card-----\n"
	<< "The id of the shopping gift card : " << std::flush;
	std::cin >> id;
	myStringStream << id << std::endl;
	std::cout << "\033[;36;1m -----the amout of consumption : \033[0m" << std::flush;
	myStringStream << "-----the amout of consumption : " << std::flush;
	std::cin >> amount;
	myStringStream << amount << std::endl;
/*	for (std::vector<ShoppingCard>::iterator i = allShoppingCards.begin(); i != allShoppingCards.end(); ++i)
	{
		i->print();
 	}*/

	/**
	 * find the shopping card and comfirm the
	 * balance before settle the account.
	 */
	auto i = allShoppingCards.find(id);
	try{
		if (i != allShoppingCards.end()) {
			mark = 1;
			if(i->second->returnBal() > amount){
				i->second->returnBal() -= amount;
				bill -= amount;

				/**
				 * The user interface.
				 * And the information about remaining bill.
				 */
				std::cout << "\033[;34;1m -----The money remained in the shopping card : \033[0m"
				<< i->second->returnBal() << std::endl;

				std::cout << "\033[;34;1m -----The money needed : \033[0m"
				<< bill << std::endl;

				myStringStream << "-----The money remained in the shopping card : "
				<< i->second->returnBal() << std::endl;

				myStringStream << "-----The money needed : "<< bill << std::endl;

			}else{
				throw Myerror("\033[;31;1m The balance is not enough.\033[0m");
			}
		}
		if(i == allShoppingCards.end()){
			throw Myerror("\033[;31;1m -----Illegal id.\033[0m");
		}

	}catch(Myerror error){
		std::cout << "\033[;34;1m \n-----Payment error handler-----\n\033[0m"
		<< error.what() << std::endl;
		myStringStream << "\n-----Payment error handler-----\n"
		<< error.what() << std::endl;
	}

	/**
	 * update the shoppingcards.txt
	 */
	update(allShoppingCards, "newshoppingcardfile.txt", 2);

	return false;

}

/**
 * manage the payment module.
 * @param M [description]
 */
void Payment::run(Membership M){
	double status = 0;
	bool isDone = false;
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
	 * The user interface.
	 */
	std::cout << "\033[;34;1m \n-----Payment module-----\n\033[0m"
	<< "\033[;34;1mThe money needed to pay:\033[0m"
	<< bill << "\n"
	<< "\033[;36;1m command : \033[0m" << std::flush;
	myStringStream << "\n-----Payment module-----\n"
	<< "The money needed to pay:"
	<< bill << "\n"
	<< "command : " << std::flush;
	std::cin >> command;
	myStringStream << command << std::endl;

	/**
	 * select the payment approach here.
	 */
	while(command != "quit"){
		if(command == "cash"){

			/**
			 * payment approach : cash.
			 */
			isDone = cash();
		}else if(command == "bank"){

			/**
			 * payment approach : bank card.
		 	*/
			isDone = bankCard();
		}else if(command == "shop"){

			/**
			 * payment approach : shopping gift card.
			 */
			isDone = shoppingCard();
		}

		/**
		 * quit the module when the transaction is done.
		 */
		if(isDone){
			break;
		}

		/**
		 * The user interface.
		 */
		std::cout << "\033[;34;1m \n-----Payment module-----\n\033[0m"
		<< "\033[;36;1m command : \033[0m" << std::flush;
		myStringStream << "\n-----Payment module-----\n"
		<< "command : " << std::flush;
		std::cin >> command;
		myStringStream << command << std::endl;
	}

	/**
	 * output the shopping list to the command list.
	 */
	showList();

	/**
	 * upgrade the member point.
	 */
	M.addPoint();

	/**
	 * upgrade the member 's level.
	 */
	M.upgrade();

	/**
	 * display the current Member to confirm the upgrade.
	 */
	M.displayTheMember();

	/**
	 * update the member data.
	 * use 'new' command to creat a a new file,
	 * use 'old' command to override the old file.
	 */
	update(allMembers, "newMemberdata.txt", 1);

	/**
	 * clean the shopping list.
	 */
	cleanTheShoppingList();

	return;

}

template<typename T, typename W>
void Payment::update(std::map<T, W> all, std::string file, int status){
	std::string command;
	std::cout << "\033[;34;1m \n-----UPDATE CHECK MODULE-----\n\033[0m"
	<< "\033[;34;1m -----Your data will be changed, please select a mod : \n\033[0m"
	<< "\033[;31;1m NEW : creat a new file .\nATE : append to the old file .\n\033[0m"
	<< "\033[;36;1m command : \033[0m" << std::flush;

	/**
	 * select the update method.
	 */
	try{
		std::cin >> command;
		if(command == "new" || command == "NEW"){
			std::ofstream newFile(file, std::ios_base::out);
			for (auto i = all.begin(); i != all.end(); ++i){
				(*((*i).second)).fprint(newFile);
			}
		}else if(command == "ate" || command == "ATE"){
			if (status == 1){
				std::ofstream oldFile("members.txt", std::ios_base::out);
				for (auto i = all.begin(); i != all.end(); ++i){
					(*((*i).second)).fprint(oldFile);
				}
			}else if(status == 2){
				std::ofstream oldFile("shoppingcards.txt", std::ios_base::out);
				for (auto i = all.begin(); i != all.end(); ++i){
					(*((*i).second)).fprint(oldFile);
				}
			}
		}else{
			throw Myerror("\033[;31;1m -----The command does exit.\033[0m");
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

	/**
	 * display the payment infomation and shopping list to the screen
	 * and output them into an output file simultaneously.
	 * @param  i [description]
	 * @return   [description]
	 */
	std::ofstream of("paymentOutput.txt", std::ofstream::out);
	of << "\n-----SHOPPING LIST-----" << std::endl;
	for (std::vector<Goods>::iterator i = Checkout::goodsList.begin(); i != Checkout::goodsList.end(); ++i){
		of << *i << std::flush;
		std::cout << *i << std::flush;
	}
	of << myStringStream.str() << std::endl;
	of.close();
}
