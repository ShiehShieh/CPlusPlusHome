#ifndef NOMnommax
#define NOMnommax

#include <iostream>
#include <vector>
#include <string>

/**
 * [nommax description]
 * @param  v [description]
 * @return   [description]
 */
const int& nommax(const std::vector<int> &v)
{
	if (!v.size())
	{
		return 0;
	}
	int a = v[0];
	for (auto beg = v.cbegin(); beg != v.cend(); ++beg)
	{
		if (beg != v.cend()-1 && *beg < *(beg+1))
		{
			a = *(beg+1);
		}
	}
	std::cout << "int" << std::endl;
	return a;
}

/**
 * [nommax description]
 * @param  v [description]
 * @return   [description]
 */
const float& nommax(const std::vector<float> &v)
{
	if (!v.size())
	{
		return 0;
	}
	float a = v[0];
	for (auto beg = v.cbegin(); beg != v.cend(); ++beg)
	{
		if (beg != v.cend()-1 && *beg < *(beg+1))
		{
			a = *(beg+1);
		}
	}
	std::cout << "float" << std::endl;
	return a;
}

/**
 * [nommax description]
 * @param  v [description]
 * @return   [description]
 */
const std::string& nommax(const std::vector<std::string> &v)
{
	if (!v.size())
	{
		return " ";
	}
	std::string a = v[0];
	for (auto beg = v.cbegin(); beg != v.cend(); ++beg)
	{
		if (beg != v.cend()-1 && *beg < *(beg+1))
		{
			a = *(beg+1);
		}
	}
	std::cout << "string" << std::endl;
	return a;
}

/**
 * [nommax description]
 * @param  p [description]
 * @param  n [description]
 * @return   [description]
 */
int nommax(int *p, int n)
{
	if (!p)
	{
		return 0;
	}
	int *a = p;
	for (int i = 0; i < n; ++i, ++p)
	{
		if (*p < *(p+1))
		{
			a = p+1;
		}
	}
	std::cout << "int'" << std::endl;
	return *a;
}

/**
 * [nommax description]
 * @param  p [description]
 * @param  n [description]
 * @return   [description]
 */
float nommax(float *p, int n)
{
	if (!p)
	{
		return 0;
	}
	float *a = p;
	for (int i = 0; i < n; ++i, ++p)
	{
		if (*p < *(p+1))
		{
			a = p+1;
		}
	}
	std::cout << "float'" << std::endl;
	return *a;
}

/**
 * [nommax description]
 * @param  p [description]
 * @param  n [description]
 * @return   [description]
 */
std::string nommax(std::string *p, int n)
{
	if (!p)
	{
		return " ";
	}
	std::string *a = p;
	for (int i = 0; i < n; ++i, ++p)
	{
		if (*p < *(p+1))
		{
			a = p+1;
		}
	}
	std::cout << "float'" << std::endl;
	return *a;
}

#endif