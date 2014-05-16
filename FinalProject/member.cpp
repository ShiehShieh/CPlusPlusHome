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
	os << "memberShipNumber : " << memberShipNumber << "\n"
	<< "name : " << name << "\n"
	<< "gender : " << gender<< "\n"
	<< "phone : " << phone << "\n"
	<< "level : " << level << "\n"
	<< "memberPoint : " << memberPoint << std::endl;
}
