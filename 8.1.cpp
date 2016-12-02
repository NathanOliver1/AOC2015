#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdint>

std::size_t parseStringSize(const std::string &);

int main()
{
	std::ifstream fin("test.txt");
	std::string line;
	long long file_size = 0, string_size = 0;
	while (std::getline(fin, line))
	{
		file_size += line.size();
		string_size += parseStringSize(line);
	}
	std::cout << file_size - string_size;
}

std::size_t parseStringSize(const std::string& line)
{
	std::string builder;
	for (std::size_t i = 1; i < line.size() - 1; i++)
	{
		if (line[i] == '\\' && line[i + 1] == 'x')
		{
			builder += "_";
			i += 3;
		}
		else if (line[i] == '\\')
		{
			builder += "_";
			i++;
		}
		else
			builder += line[i];
	}
	return builder.size();
}