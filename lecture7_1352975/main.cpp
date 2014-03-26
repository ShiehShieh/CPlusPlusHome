#include <iostream>
#include <functional>
#include "MYERR.h"
#include "MYSTACK.h"

int main(int argc, char const *argv[])
{
	Stack<int> stack;
	int i = 5;

	std::cout << "     Push one element into the stack." << std::endl;
	stack.push(i);
	std::cout << "          " << std::flush;
	stack.print();

	std::cout << "     Push one element into the stack." << std::endl;
	stack.push(i);
	std::cout << "          " << std::flush;
	stack.print();

	std::cout << "     Pop one element from the stack." << std::endl;
	stack.pop();
	std::cout << "          " << std::flush;
	stack.print();

	std::cout << "\n      Is it empty:" << stack.empty()
	<< "\n      Is it full:" << stack.full()
	<< "\nthe toppest element is:" << stack.peek()
	<< "\nthe size of the stack is:" << stack.size() << std::endl;
	stack.pop();
	stack.print();

	stack.pop();
	std::cout << "\n     Try to push 25 element into the stack." << std::endl;
	for (int i = 0; i < 25; ++i){
		stack.push(i);
	}

	return 0;
}