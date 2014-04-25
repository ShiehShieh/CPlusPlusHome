/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: mamber.h
 *description		: include the definition of the member
 */
#ifndef MEMBER
#define MEMBER

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Member;
std::vector<Member> allMembers;

/**
 * represent all the Member in the store.
 */
class Member
{
public:
	Member(std::ifstream &is);
	Member(int msn, std::string na, char gen, std::string pho, int level, std::string mp):
	memberShipNumber(msn), name(na), gender(gen), phone(pho), level(level), memberPoint(mp){}
	void print(std::ostream &os);
	int returnNumber(){
		return memberShipNumber;
	}
	int returnLevel(){
		return level;
	}
	~Member(){}

private:
	int memberShipNumber = 0;
	std::string name;
	char gender;
	std::string phone;
	int level;
	std::string memberPoint;
};

Member::Member(std::ifstream &is){
	std::string strin, str;
	while(is >> strin){
		str += " " + strin;
	}

	/**
	 * [inString store all the input data.]
	 * @str [store the input data temporarily]
	 */
	std::istringstream inString(str);
	int memberShipNumber;
	std::string name;
	char gender;
	std::string phone;
	int level;
	std::string memberPoint;
	while(inString){
		inString >> memberShipNumber >> name >> gender >>
		phone >> level >> memberPoint;
		allMembers.push_back(Member(memberShipNumber, name, gender, phone, level, memberPoint));
	}
}

void Member::print(std::ostream &os = std::cout){
	os << "memberShipNumber : " << memberShipNumber << "\n"
	<< "name : " << name << "\n"
	<< "gender : " << gender<< "\n"
	<< "phone : " << phone << "\n"
	<< "level : " << level << "\n"
	<< "memberPoint : " << memberPoint << std::endl;
}

std::ostream& operator<<(std::ostream &os, Member& M){
	M.print(os);
	return os;
}

#endif