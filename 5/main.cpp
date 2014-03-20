#include <iostream>
#include <string>
#include <memory>
#include "TRAVELER.h"
#include "TIME.h"
#include "CLONE.h"

int main(int argc, char const *argv[])
{
	BusinessTraveler b;
	TimeInherit T;
	Cloneone one;
	Clonetwo two;
	CloneBase *cb;

	findtime(&T);
	cb = one.clone();
	cb->print();
	cb = two.clone();
	cb->print();

	return 0;
}