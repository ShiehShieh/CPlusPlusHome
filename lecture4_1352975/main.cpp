#include <iostream>
#include <vector>
#include <array>
#include "USER_PROF.h"
#include "MATRIX.h"

int main(int argc, char const *argv[]){
	std::array<float, 16> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
	Matrix M, M1(ar), M2(ar);

	M.print();
	M.add(M1);
	M.print();
	M.multiply(M2);
	M.print();
	M = M1 + M2;
	M.print();
	M += M1;
	M.print();
	std::cout << M(2, 2) << std::endl;

	User_prof u;
	Player p1, p2, p3, p4, p5;
	u.login(p1);
	u.login(p2);
	u.login(p3);
	u.login(p4);
	u.login(p5);
	std::cout << u << std::endl;
	u.logout();
	u.logout();
	std::cout << u << std::endl;

	return 0;
}