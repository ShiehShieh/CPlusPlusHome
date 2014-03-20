#ifndef TRAVELER
#define TRAVELER

#include <string>

class Traveler
{
public:
	Traveler(std::string str):internal(str){}
	virtual ~Traveler(){}
	Traveler(const Traveler &T):internal(T.internal){}
	Traveler& operator=(const Traveler &T)
	{
		this->internal = T.internal;
		return *this;
	}

protected:
	std::string internal;
};

class Pager
{
public:
	Pager(std::string str):internal(str){}
	~Pager(){}
	Pager(const Pager &P):internal(P.internal){}
	Pager& operator=(const Pager &P)
	{
		this->internal = P.internal;
		return *this;
	}

private:
	std::string internal;
};

class BusinessTraveler: public Traveler
{
public:
	BusinessTraveler():Traveler(" "), pager(" "){}
	BusinessTraveler(std::string str):Traveler(str), pager(str){}
	BusinessTraveler(const BusinessTraveler &b):Traveler(b.internal), pager(b.pager){}
	BusinessTraveler& operator=(const BusinessTraveler &b)
	{
		this->internal = b.internal;
		this->pager = b.pager;
		return *this;
	}

private:
	Pager pager;
};

#endif