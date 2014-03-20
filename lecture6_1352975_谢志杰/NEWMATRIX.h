#ifndef NEWMATRIX
#define NEWMATRIX

#include <iostream>
#include <array>
#include <algorithm>
#include <memory>
#include <locale>
#include <cstring>
#include <utility>
#include "MYERR.h"

template <typename SomeClass, int row, int column>
class NewMatrix;
template <typename SomeClass, int row, int column>
std::ostream& operator<<(std::ostream& os, const NewMatrix<SomeClass, row, column>& M);

template <typename SomeClass, int row, int column>
class NewMatrix{
friend std::ostream& operator<<<SomeClass, row, column>(std::ostream& os, const NewMatrix<SomeClass, row, column>& M);

public:
	NewMatrix():i(0){
		pToClass = new SomeClass[row*column];
		while(std::cin >> pToClass[i] && i < row*column){
			++i;
		}
	}
//	NewMatrix(const std::array<, 16> initarray):stdArray(initarray), i(0){}
	NewMatrix(const SomeClass *pfArray):i(0){
		pToClass = new SomeClass[row*column];
		while(i < row*column){
			pToClass[i] = pfArray[i];
			++i;
		}
	}
	~NewMatrix(){
		delete [] pToClass;
	}
	void add(const NewMatrix<SomeClass, row, column>& M);
	void multiply(const NewMatrix<SomeClass, row ,column>& M);
	std::ostream& print() const;
	SomeClass& operator()(int row_, int column_);
	const SomeClass* getPointer() const{
		return pToClass;
	}
	const std::pair<int, int> getRC() const{
		return std::make_pair(row, column);
	}
//	const std::array<float, 16>& getarray() const{
//		return this->stdArray;
//	}
//	float operator(int row, int column) const;

private:
	int i = 0;
	std::shared_ptr<SomeClass> pToClassShared;
	SomeClass *pToClass = nullptr;
};

template <typename SomeClass, int row, int column>
void NewMatrix<SomeClass, row, column>::add(const NewMatrix<SomeClass, row, column>& M){
	const SomeClass *pToM = M.getPointer();
	try{
		if (this->getRC() != M.getRC()){
			throw MyErr("The size of two Matrix are different.\nPlease try again.");
		}
		for (int i = 0; i < row*column; ++i){
		this->pToClass[i] += pToM[i];
		}
	}catch(MyErr& Err){
		std::cout << Err.what() << std::endl;
	}

}

template <typename SomeClass, int row, int column>
void NewMatrix<SomeClass, row, column>::multiply(const NewMatrix<SomeClass, row, column>& M){
	SomeClass *pToM = M.getPointer();
	try{
		if (this->getRC().second != M.getRC().first){
			throw MyErr("The two Matrix can't be multiplied.\nPlease try again.");
		}
		for (int i = 0; i < row*column; ++i){
		this->pToClass[i] *= pToM[i];
		}
	}catch(MyErr& Err){
		std::cout << Err.what() << std::endl;
	}
}

template <typename SomeClass, int row, int column>
NewMatrix<SomeClass, row, column>& operator+=(NewMatrix<SomeClass, row, column>& M1, const NewMatrix<SomeClass, row, column>& M2){
	M1.add(M2);
	return M1;
}

template <typename SomeClass, int row, int column>
NewMatrix<SomeClass, row, column> operator+(const NewMatrix<SomeClass, row, column>& M1, const NewMatrix<SomeClass, row, column>& M2){
	SomeClass arr[(M1.getRC().first)*(M1.getRC().second)];
	memset(arr, 0, sizeof(arr));
	NewMatrix<SomeClass, row, column> newOne(arr);

	newOne += M1;
	newOne += M2;

	return newOne;
}

template <typename SomeClass, int row, int column>
SomeClass& NewMatrix<SomeClass, row, column>::operator()(int row_, int column_){
	return this->pToClass[(row_-1)*column+column_-1];
}

template <typename SomeClass, int row, int column>
std::ostream& operator<<(std::ostream& os, const NewMatrix<SomeClass, row, column>& M){
	for (int i = 0; i < (M.getRC().first)*(M.getRC().second); ++i){
		os << M.pToClass[i] << "     ";
		if ((i+1)%column == 0)
		{
			std::cout << "\n";
		}
	}
	os << std::endl;

	return os;
}

template <typename SomeClass, int row, int column>
std::ostream& NewMatrix<SomeClass, row, column>::print() const{
	std::cout << *this << std::endl;
	return std::cout;
}

#endif