#ifndef MYSTACK
#define MYSTACK

#include <iostream>
#include <string>
#include <memory>
#include "MYERR.h"

template<typename T>class Stack;

template <typename T>
std::ostream& operator<<(std::ostream& os, Stack<T> stack);

template <typename T>
class Stack{
	friend std::ostream& operator<<<T>(std::ostream& os, Stack<T> stack);
public:
	Stack(){}
	~Stack(){}
	bool push(T t);
	bool pop();
	int size();
	bool empty();
	bool full();
	T& peek();
	void print();

private:
	std::allocator<T> allo;
	T* pToStackConst = allo.allocate(20);
	T* pToStack = pToStackConst;
};

template <typename T> bool Stack<T>::push(T t){
	try{
		if (20 == pToStack - pToStackConst){
			throw filling_to_full("Trying to fill elements to a full stack.");
		}
		allo.construct(pToStack, t);
		++pToStack;
	}catch(filling_to_full& err){
		std::cout << err.what() << std::endl;
	}
	return true;
}

template <typename T> bool Stack<T>::pop(){
	try{
		if (pToStack == pToStackConst){
			throw getting_from_empty("Trying to get elements from an empty stack.");
		}
		allo.destroy(pToStack);
		--pToStack;
	}catch(getting_from_empty& err){
		std::cout << err.what() << std::endl;
	}
	return true;
}

template <typename T> int Stack<T>::size(){
	return pToStack - pToStackConst;
}

template <typename T> bool Stack<T>::empty(){
	return pToStack == pToStackConst;
}

template <typename T> bool Stack<T>::full(){
	return 20 == pToStack - pToStackConst;
}

template <typename T> T& Stack<T>::peek(){
	return *pToStack;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Stack<T> stack){
	for (T* pointer = stack.pToStackConst; pointer != stack.pToStack; ++pointer){
		std::cout << *pointer << "     ";
	}
	std::cout << std::endl;
	return os;
}

template <typename T> void Stack<T>::print(){
	std::cout << *this << std::endl;
}

#endif