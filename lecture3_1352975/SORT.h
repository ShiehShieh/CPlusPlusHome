#ifndef SORT
#define SORT

#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

extern char easytolower(char in);
bool newsort(const std::string str1, const std::string str2);

void mysort()
{
	std::string str;
	std::vector<std::string> vs;
	std::ifstream hinfile("article.txt");
	std::ofstream houtfile("3_2out.txt");

	while(hinfile >> str)
	{
		std::transform(str.begin(), str.end(), str.begin(), easytolower);
		if (str.find_first_of("qwertyuiopasdfghjklzxcvbnm") + 1)
		{
			str = str.substr(str.find_first_of("qwertyuiopasdfghjklzxcvbnm"), str.find_last_of("qwertyuiopasdfghjklzxcvbnm")+1);
			vs.push_back(str);
		}
	}
	std::sort(vs.begin(), vs.end(), newsort);
	for (auto &i : vs)
	{
		houtfile << i << std::endl;
	}

	hinfile.close();
	houtfile.close();
}

bool newsort(const std::string str1, const std::string str2)
{
	return str1.size() < str2.size();
}

#endif