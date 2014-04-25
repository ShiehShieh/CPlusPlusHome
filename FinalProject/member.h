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

	/**
	 * initialize the class by a ifstream.
	 */
	Member(std::ifstream &is);

	/**
	 * initialize the class by mutiple argument.
	 */
	Member(int msn, std::string na, char gen, std::string pho, int level, int mp):
	memberShipNumber(msn), name(na), gender(gen), phone(pho), level(level), memberPoint(mp){}

	/**
	 * output the Member to the command line.
	 * @param os a ostream with a default value -- std::cout.
	 */
	void print(std::ostream &os);

	/**
	 * return data member--number.
	 * @return [description]
	 */
	int returnNumber(){
		return memberShipNumber;
	}

	/**
	 * return data member--level.
	 * @return [description]
	 */
	int returnLevel(){
		return level;
	}

	/**
	 * reset the level.
	 * @param levels [description]
	 */
	void setLevel(int levels){
		level = levels;
	}

	double returnPoint(){
		return memberPoint;
	}

	/**
	 * reset the member point
	 */
	void addPoint(double point){
		memberPoint += point;
	}

	/**
	 * destructor.
	 */
	~Member(){}

private:
	int memberShipNumber = 0;
	std::string name;
	char gender;
	std::string phone;
	int level;
	double memberPoint;
};

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
		allMembers.push_back(Member(memberShipNumber, name, gender, phone, level, memberPoint));
	}
}

/**
 * output the Member to the command line.
 * @param os [description]
 */
void Member::print(std::ostream &os = std::cout){
	os << "memberShipNumber : " << memberShipNumber << "\n"
	<< "name : " << name << "\n"
	<< "gender : " << gender<< "\n"
	<< "phone : " << phone << "\n"
	<< "level : " << level << "\n"
	<< "memberPoint : " << memberPoint << std::endl;
}

/**
 * output the Member with 'print()'.
 */
std::ostream& operator<<(std::ostream &os, Member& M){
	M.print(os);
	return os;
}

#endif