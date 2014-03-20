#include <iostream>
#include <fstream>
#include <map>
#include <set>

char easytolower(char in){
	if(in<='Z' && in>='A')
		return in-('Z'-'z');
	return in;
}

int main(int argc, char const *argv[]){
	std::ifstream hInFile("article.txt");
	std::string str;
	int i = 0;
//	infile >> str;
//	std::cout << str << std::endl;
	while(hInFile >> str){
		std::transform(str.begin(), str.end(), str.begin(), easytolower);
		if (str.find_first_of("qwertyuiopasdfghjklzxcvbnm") + 1){
			str = str.substr(str.find_first_of("qwertyuiopasdfghjklzxcvbnm"), str.find_last_of("qwertyuiopasdfghjklzxcvbnm")+1);
		}
		if (str == "that"){
			++i;
		}
	}
	std::cout  << i << std::endl;
	return 0;
}