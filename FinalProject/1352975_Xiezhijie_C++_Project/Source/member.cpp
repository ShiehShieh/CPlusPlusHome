/**
 * @file    : member.cpp
 * @brief
 * @author  : 谢志杰Xie zhijie
 * @version : 1.0
 * @date    : 2014-05-06
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "member.h"

Member::Member(std::ifstream &is){
	std::string strin, str;

	/**
	 * read file here.
	 */
	while(is >> strin){
		str += " " + strin;
	}

	/**
	 * [inString will be used to store all the input data.]
	 * @str [store the input data temporarily]
	 */
	std::istringstream inString(str);
	int memberShipNumber;
	std::string name;
	char gender;
	std::string phone;
	int level;
	int memberPoint;

	/**
	 * construct the Member, and push all the object into the vector.
	 */
	while(inString){
		inString >> memberShipNumber >> name >> gender >>
		phone >> level >> memberPoint;
		auto var = new Member(memberShipNumber, name, gender, phone, level, memberPoint);
		allMembers.insert(std::make_pair(memberShipNumber, var));
	}
}

/**
 * output the Member to the command line.
 * @param os [description]
 */
void Member::print(std::ostream &os) const{
	os << "\033[;33;1m memberShipNumber : \033[0m" << memberShipNumber << "\n"
	<< "\033[;33;1m name : \033[0m" << name << "\n"
	<< "\033[;33;1m gender : \033[0m" << gender<< "\n"
	<< "\033[;33;1m phone : \033[0m" << phone << "\n"
	<< "\033[;33;1m level : \033[0m" << level << "\n"
	<< "\033[;33;1m memberPoint : \033[0m" << memberPoint << std::endl;
}

/**
 * output the member information to a file.
 *
 */
void Member::fprint(std::ostream &os) const{
	os << memberShipNumber << "\n"
	<< name << "\n"
	<< gender<< "\n"
	<< phone << "\n"
	<< level << "\n"
	<< memberPoint << std::endl;
}
