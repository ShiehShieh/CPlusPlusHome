#ifndef AA
#define AA

#include <memory>

class Aa
{
public:
	Aa(){}
	~Aa(){}
	virtual Aa* as(){Aa *A = this;return A;}
	virtual int ad() = 0;

};

#endif