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
	std::vector<Member>::difference_type returnMemberSize(){
		return memberSize;
	}

	void displayTheMember(){
		(*(allMembers.begin() + memberSize)).print();
	}

	~Membership(){}

private:
	int level;
	double bill;
	std::vector<Member>::difference_type memberSize = 0;

	double discount();
	void addPoint();
	void upgrade();
	void deduction();
};

#endif
