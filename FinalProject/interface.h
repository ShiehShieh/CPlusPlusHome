#ifndef INTERFACE
#define INTERFACE

#include <string>
#include <vector>

class Interface
{
public:

	/**
	 * initialize the class with an integer and a string
	 */
	Interface(int n, std::vector<std::string> v;):times(n), vString(v){
		run();
	}

	~Interface(){}

private:
	int times;
	std::vector<std::string> vString;

	void run();
};

#endif