#ifndef COUNT
#define COUNT

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <set>

char easytolower(char in){
	if(in<='Z' && in>='A')
		return in-('Z'-'z');
  return in;
}

int count(){
	std::set<std::string> word;
	std::string str;
	std::map<std::string, int> wordtime;
	std::set<std::string> exclusive;
	std::ifstream hinfile("article.txt");
	std::ifstream hinfile2("exclusive.txt");
	std::ofstream houtfile1("3_1_1out.txt");
	std::ofstream houtfile2("3_1_2out.txt");

	while(hinfile2 >> str){
		exclusive.insert(str);
	}
	while(hinfile >> str){
		std::transform(str.begin(), str.end(), str.begin(), easytolower);
		if (str.find_first_of("qwertyuiopasdfghjklzxcvbnm") + 1){
			str = str.substr(str.find_first_of("qwertyuiopasdfghjklzxcvbnm"), str.find_last_of("qwertyuiopasdfghjklzxcvbnm")+1);
			if (!exclusive.count(str))
			{
				word.insert(str);
				++wordtime[str];
			}
		}
	}
	for (auto beg = word.cbegin(); beg != word.cend(); ++beg){
		houtfile1 << *beg << "  's times:  " << wordtime[*beg] << std::endl;
	}
	for (auto beg = word.rbegin(); beg != word.rend(); ++beg){
		houtfile2 << *beg << "  's times:  " << wordtime[*beg] << std::endl;
	}

	hinfile.close();
	hinfile2.close();
	houtfile1.close();
	houtfile2.close();

	return 0;
}

#endif