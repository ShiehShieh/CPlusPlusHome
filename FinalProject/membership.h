#ifndef MEMBERSHIP
#define MEMBERSHIP

#include <vector>
#include "member.h"

class Membership
{
	friend class Payment;
public:
	Membership(){}
	void run();

	/**
	 * return bill
	 * @param  status received from 'discount()', which can determin
	 *                the output of this function.
	 * @return        [description]
	 */
	double returnBill(double status){
		if(status == 1){
			deduction();
			return bill;
		}
		return status;
	}

	/**
	 * return the member size.
	 * @return [description]
	 */
	std::map<int, Member*>::iterator returnMemberSize(){
		return memberSize;
	}

	/**
	 * show the membet information to checkout the update.
	 */
	void displayTheMember(){
		memberSize->second->print();
	}

	~Membership(){}

private:
	int level;
	double bill;
	std::map<int, Member*>::iterator memberSize = allMembers.end();

	double discount();
	void addPoint();
	void upgrade();
	void deduction();
};

#endif
