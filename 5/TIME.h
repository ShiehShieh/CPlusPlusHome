#ifndef TIME
#define TIME

#include <ctime>
#include <iostream>

class TimeBaseOne
{
public:
	TimeBaseOne(){}
	virtual ~TimeBaseOne(){}
	virtual int virtualf(){return 5;}
	int nonvirtualf(){return 5;}

private:
};

class TimeInherit : public TimeBaseOne
{
public:
	TimeInherit(){}
	~TimeInherit(){}

private:
};

auto findtime(TimeBaseOne *T) -> int
{
	int a = 0;
	std::clock_t start = std::clock();
	for (int i = 1000000; i > 0; --i)
	{
		a += T->virtualf();
	}
	std::clock_t end1 = std::clock();
	std::cout << "Virtual founction call's time : " << 1000.0 * (end1 - start) / CLOCKS_PER_SEC << std::endl;
	for (int i = 1000000; i > 0; --i)
	{
		a += T->nonvirtualf();
	}
	std::clock_t end2 = std::clock();
	std::cout << "Non-virtual founction call's time : " << 1000.0 * (end2 - end1) / CLOCKS_PER_SEC << std::endl;
	return 0;
}

#endif