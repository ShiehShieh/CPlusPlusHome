/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: checkout.h
 *description		: include the definition of checkout, which is used to
 *					  manage the checkout mode.
 */
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "goods.h"
#include "membership.h"
#include "checkout.h"

//std::vector<Goods> goodsList;
std::vector<Goods> Checkout::goodsList;

int Checkout::interface(std::string &str, std::string &str1, std::string &str2, int status){
	std::cout << "-----Checkout module.-----\n"
	<< "command/commodity : " << std::flush;
	std::cin >> str1;
	if (str1 == "quit"){
		return status;
	}
	std::cout << "number : (pass 'p' to skip)" << std::flush;
	std::cin >> str2;
	if (str2 != "p"){
		str = str1 + " " + str2;
	}else{
		str = str1 + " 1";
	}

	/**
	 * This function return "5", which mean that chekcout module can
	 * be continued.
	 */
	return 5;

}

/**
 * manage the checkout module.
 * @return [description]
 */
int Checkout::run(){

	std::string str, str1, str2;
	/**
	 * Start the membership module.
	 */
	membership.run();

	//getline();
	
	/**
	 * the user interface.
	 */
	int status = interface(str, str1, str2, 0);
	if(status == 0){
		return 0;
	}

	/**
	 * entry 'quit' to jump out of this loop.
	 */
	while(true){
		std::istringstream iss(str);
		iss >> commodity;
		if(iss >> number){}

		/**
		 * find the particular goods.
		 */
		find();

		/**
		 * the user interface.
		 */
		status = interface(str, str1, str2, 1);
		if(status == 1){
			return 1;
		}
	}

	return 1;

}

/**
 * Find the correct purchase.
 */
void Checkout::find(){
	for (std::vector<Goods>::iterator i = allGoods.begin(); i != allGoods.end(); ++i)
	{
		if (i->returnCom() == commodity)
		{
			int total = i->returnBenchmark() * number * i->returnDiscount();
			i->print();
			std::cout << "total: " << total << std::endl;
			goodsList.push_back(Goods(*i));
			goodsList.back().setCount(number);
			std::cout << "count: " << number << std::endl;
		}
	}
}
