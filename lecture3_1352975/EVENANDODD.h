#ifndef EVENANDODD
#define EVENANDODD

#include <fstream>
#include <iterator>
#include <iostream>
#include <vector>

void evenandodd()
{
	std::ofstream houtfile1("3_3_1out.txt");
	std::ofstream houtfile2("3_3_2out.txt");	
	std::istream_iterator<int> eof;
	std::istream_iterator<int> itofis(std::cin);
	std::ostream_iterator<int> itofout1(houtfile1, " ");
	std::ostream_iterator<int> itofout2(houtfile2, "\n");
	std::vector<int> vi;

	while(itofis != eof)
	{
		vi.push_back(*itofis++);
	}
	for(auto i : vi)
	{
		if (i%2)
		{
			itofout1 = i;
		}
		else
		{
			itofout2 = i;
		}
	}

}

#endif