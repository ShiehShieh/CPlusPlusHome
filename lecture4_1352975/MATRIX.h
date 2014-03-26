#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <array>
#include <algorithm>
#include <locale>

class Matrix{
	friend std::ostream& operator<<(std::ostream& os, const Matrix& M);

public:
	Matrix():i(0){
		while(std::cin >> stdArray[i] && i < 16){
			++i;
		}
	}
	Matrix(const std::array<float, 16> initarray):stdArray(initarray), i(0){}
	Matrix(const float *pfArray):i(0){
		while(i < 16){
			stdArray[i] = pfArray[i];
			++i;
		}
	}
	~Matrix(){}
	void add(const Matrix& M);
	void multiply(const Matrix& M);
	std::ostream& print() const;
	float& operator()(int row, int column);
	const std::array<float, 16>& getarray() const{
		return this->stdArray;
	}
//	float operator(int row, int column) const;

private:
	int i = 0;
	std::array<float, 16> stdArray;
};

float addfloat(float f1,float f2){
	return f1 + f2;
}

float multiplyfloat(float f1, float f2){
	return f1 * f2;
}

void Matrix::add(const Matrix& M){
	std::transform(this->stdArray.begin(), this->stdArray.end(), M.getarray().begin(), this->stdArray.begin(), addfloat);
}

void Matrix::multiply(const Matrix& M){
	std::transform(this->stdArray.begin(), this->stdArray.end(), M.getarray().begin(), this->stdArray.begin(), multiplyfloat);
}

Matrix& operator+=(Matrix& M1, const Matrix& M2){
	M1.add(M2);
	return M1;
}

Matrix operator+(const Matrix& M1, const Matrix& M2){
	std::array<float, 16> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	Matrix newOne(arr);

	newOne += M1;
	newOne += M2;

	return newOne;
}

float& Matrix::operator()(int row, int column){
	float f = 0;
	return this->stdArray[(row-1)*4+column-1];
}

std::ostream& operator<<(std::ostream& os, const Matrix& M){
	for (int i = 0; i < 16; ++i){
		os << M.stdArray[i] << " ";
		if ((i+1)%4 == 0)
		{
			std::cout << "\n";
		}
	}
	os << std::endl;

	return os;
}

std::ostream& Matrix::print() const{
	std::cout << *this << std::endl;
	return std::cout;
}

#endif