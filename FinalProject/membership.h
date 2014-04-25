#ifndef MEMBERSHIP
#define MEMBERSHIP

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
	~Membership(){}

private:
	int level;
	double bill;
	int discount();
	void addPoint();
	void upgrade();
	void deduction();
};

#endif