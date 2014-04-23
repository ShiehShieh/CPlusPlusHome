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

class Member
{
public:
	Member(int msn, std::string na, char gen, int pho, int level, std::string mp):
	memberShipNumber(msn), name(na), gender(gen), phone(pho), level(level), memberPoint(mp){}
	void print()
	~Member(){}

private:
	int memberShipNumber = 0;
	std::string name;
	char gender;
	int phone;
	int level;
	std::string memberPoint;
};

void Member::print(){
	std::cout << memberShipNumber << "\n" << name << "\n"
	<< gender<< "\n" << phone << "\n" << level << "\n"
	<< memberPoint << std::endl;
}

std::ostream& operator<<(std::ostream &os, Member& M) const{
	M.print();
	return os
}

#endif