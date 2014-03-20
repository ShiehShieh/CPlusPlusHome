#ifndef TEMMAX
#define TEMMAX

#include <vector>
#include <string>

/**
 * 
 */
template<typename T>
T& temmax(std::vector<T> v)
{
	T t;
	if (!v.size())
	{
		return t;
	}
	T a = v[0];
	for (auto beg = v.cbegin(); beg != v.cend(); ++beg)
	{
		if (beg != v.cend()-1&&*beg<*(beg+1))
		{
			a = *(beg+1);
		}
	}
	return a;
}

/**
 * 
 */
template<typename T>
T& temmax(T *p, int n)
{
	T *t;
	if (!p)
	{
		return *t;
	}
	T *a = p;
	for (int i = 0; i<n; ++i, ++p)
	{
		if (*p<*(p+1))
		{
			a = p+1;
		}
	}
	return *a;
}

#endif