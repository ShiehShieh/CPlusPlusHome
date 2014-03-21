#ifndef TEXT
#define TEXT

#include <string>
#include <iostream>

class Text{
friend std::ostream& operator<<(std::ostream &os, Text t);

public:
	Text(std::string instr1, std::string instr2, int ini):str1(instr1), str2(instr2), i(ini){}
	Text(Text &t);
	Text& operator=(Text &t);
	~Text(){}

private:
	std::string str1;
	std::string str2;
	int i = 5;
};

std::ostream& operator<<(std::ostream &os, Text t){
	os << t.str1 << " " << t.str2 << " " << t.i << std::endl;
	return os;
}

Text::Text(Text &t){
	str1 = t.str1;
	str2 = t.str2;
	i = t.i;
}

Text& Text::operator=(Text &t){
	str1 = t.str1;
	str2 = t.str2;
	i = t.i;
	return *this;
}

struct Textstruct{
	Textstruct(std::string instr1, std::string instr2, int ini):str1(instr1), str2(instr2), i(ini){}
	std::string str1;
	std::string str2;
	int i = 5;
};

#endif