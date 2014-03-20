#include <iostream>
#include <vector>
#include <string>
//#include <utility>
#include "nommax.h"
#include "temmax.h"
//#include <array>
//我用的是我以前的编程风格，现在改了。
int main(int argc, char const *argv[])
{
	int i;
	float f;
	std::string str;
	std::vector<int> vi;
	std::vector<float> vf{1.5,2.5,3.5,4.5,5.5};
	std::vector<std::string> vs;
/*
	std::array<int, n1> ai;
	std::array<float, n2> af;
	std::array<std::string, n3> as;
*/
	int ai[5];
	float af[5];
	std::string as[5];

	f = nommax(vf);
	std::cout << f << std::endl;
	f = temmax(vf);
	std::cout << f << std::endl;

	return 0;
}