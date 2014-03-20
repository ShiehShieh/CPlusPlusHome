#ifndef CLONE
#define CLONE

#include <iostream>
#include <memory>

class CloneBase
{
public:
	CloneBase(){}
	virtual ~CloneBase(){}
	CloneBase(const CloneBase &C){}
	virtual CloneBase* clone(){return this;}
	virtual void print() = 0;

private:
};

class Cloneone : public CloneBase
{
public:
	Cloneone(){}
	~Cloneone(){}
	Cloneone(const Cloneone &C){}
	CloneBase* clone() override{return this;}
	void print() override{std::cout << mark << std::endl;}

private:
	int mark = 1;
};

class Clonetwo : public CloneBase
{
public:
	Clonetwo(){}
	~Clonetwo(){}
	Clonetwo(const Cloneone &C){}
	CloneBase* clone() override{return this;}
	void print() override{std::cout << mark << std::endl;}

private:
	int mark = 2;
};

#endif