#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdint>

std::size_t builtStringSize(const std::string &);

int main()
{
	std::ifstream fin("test.txt");
	std::string line;
	long long file_size = 0, string_size = 0;
	while (std::getline(fin, line))
	{
		file_size += line.size();
		string_size += builtStringSize(line);
	}
	std::cout << string_size - file_size;
}

std::size_t builtStringSize(const std::string& line)
{
	std::string builder;
	builder += "\"\\\"";
	for (std::size_t i = 1; i < line.size(); i++)
	{	
		if (line[i] == '\"')
			builder += "\\\"";
		else if (line[i] == '\\' && line[i + 1] == '\"')
		{
			builder += "\\\\\\\"";
			i++;
			continue;
		}
		else if (line[i] == '\\' && line[i + 1] == '\\')
		{
			builder += "\\\\\\\\";
			i++;
			continue;
		}
		else if (line[i] == '\\')
			builder += "\\";
		builder += line[i];
	}
	return builder.size();
}