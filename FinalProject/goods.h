/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: goods.h
 *description		: include the definition of good
 */
#ifndef GOODS
#define GOODS

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Goods;
std::vector<Goods> allGoods;
/**
 * Represent all the goods in the supermarket.
 */
class Goods
{
public:
	Goods(std::ifstream& is);
	Goods(int comm, std::string na, std::string ori, int ben):
	commodity(comm), name(na), origin(ori), benchmark(ben), count(1), discount(1){}
	void print(std::ostream &os = std::cout) const;

	/**
	 * copy constructor.
	 */
	Goods(const Goods& other){
		*this = other;
	}
	Goods& operator=(const Goods& other);
	int returnCom(){
		return commodity;
	}
/*	std::string returnName(){
		return name;
	}
	std::string returnOrigin(){
		return origin;
	}
*/	int returnBenchmark(){
		return benchmark;
	}
	int returnCount(){
		return count;
	}
	double returnDiscount(){
		return discount;
	}
	void setDiscount(double discounts){
		discount = discounts;
	}
	void setCount(int counts){
		count = counts;
	}
	~Goods(){}

private:
	int commodity;
	std::string name;
	std::string origin;
	int benchmark;
	int count;
	double discount;
};

/**
 * work with 'print()'.
 */
std::ostream& operator<<(std::ostream &os, const Goods& M){
	M.print(os);
	return os;
}

#endif