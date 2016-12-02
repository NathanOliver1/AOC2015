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
	std::ifstream fin("test.txt");
	std::map<std::pair<std::string, std::string>, int> happiness;
	std::vector<std::string> people;
	std::string to, from, gain_lose, eater;
	int happy = 0, max_happy = 0;
	{
		int amount;
		std::set<std::string> temp;
		while (fin >> from >> eater >> gain_lose >> amount >> eater >> eater >> eater >> eater >> eater >> eater >> to)
		{
			happiness[std::make_pair(from, to.substr(0, to.size() - 1))] = (gain_lose == "gain" ? amount : -amount);
			temp.insert(from);
			temp.insert(to.substr(0, to.size() - 1));
		}
		people.assign(temp.begin(), temp.end());
	}
	do
	{
		for (std::size_t i = 0; i < people.size() - 1; i++)
		{
			happy += happiness[std::make_pair(people[i], people[i + 1])];
			happy += happiness[std::make_pair(people[i + 1], people[i])];
		}
		happy += happiness[std::make_pair(people.front(), people.back())];
		happy += happiness[std::make_pair(people.back(), people.front())];
		if (happy > max_happy)
		{
			max_happy = happy;
		}
		happy = 0;
	} while (std::next_permutation(people.begin(), people.end()));
	std::cout << max_happy;
}

