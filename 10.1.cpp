#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <limits>

int main()
{
	std::string seq = "1321131112";
	for (int loop = 0; loop < 40; loop++)
	{
		std::string builder;
		int counter = 0;
		for (std::size_t i = 0; i < seq.size(); i++)
		{
			counter++;
			if (i < seq.size() - 1)
			{
				if (seq[i] != seq[i + 1])
				{
					builder += std::to_string(counter) + seq[i];
					counter = 0;
				}
			}
			else
			{
				builder += std::to_string(counter) + seq[i];
				counter = 0;
			}
		}
		seq = builder;
	}
	std::cout << seq.size();
}

