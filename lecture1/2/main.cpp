#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<float> vec;

	for (int i = 0; i < 25; ++i)
	{
		vec.push_back(i);
		std::cout << i << " " << std::flush;
	}
	std::cout << std::endl;
	for (int i = 0; i < 25; ++i)
	{
		vec[i] *= vec[i];
		std::cout << vec[i] << " " << std::flush;
	}
	std::cout << std::endl;

	return 0;
}