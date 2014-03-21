#include <iostream>
#include <memory>
//#include "EXAMPLE.h"
#include "NEWMATRIX.h"
#include "MYERR.h"

int main(int argc, char const *argv[]){
	int pI[25] = {0};
	int pI1[25] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	int pI2[25] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	NewMatrix<int, 5, 5> test(pI);
	NewMatrix<int, 5, 5> test1(pI1);
	NewMatrix<int, 5, 5> test2(pI2);

	test.print();
	test.add(test1);
	test.print();
	test = test1 + test2;
	test.print();
	test += test1;
	test.print();
	std::cout << test(2, 2) << std::endl;

	return 0;
}