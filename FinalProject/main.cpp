/**
 * student number	: 1352975
 * name				: 谢志杰Xie zhijie
 *file name			: main.cpp
 *description		: Main file.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "member.h"
#include "goods.h"
#include "shoppingcard.h"
#include "checkout.h"
#include "payment.h"
#include "mod.h"

/**
 * [main description]
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[]){
	dataInput();
//	Checkout checkout;
//	checkout.run();
	Mod mod;
	mod.run();
	return 0;
}
