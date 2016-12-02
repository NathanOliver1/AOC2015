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
	std::map<std::pair<std::string, std::string>, int> distances;
	std::vector<std::string> cities;
	std::string to, from, eater;
	int distance = 0, max_distance = 0;
	int dist;
	{
		std::set<std::string> temp;
		while (fin >> from >> eater >> to >> eater >> dist)
		{
			distances[std::make_pair(from, to)] = dist;
			temp.insert(from);
			temp.insert(to);
		}
		cities.assign(temp.begin(), temp.end());
	}
	for (const auto & e : distances)
	{
		distances[std::make_pair(e.first.second, e.first.first)] = e.second;
	}
	do
	{
		for (std::size_t i = 0; i < cities.size() - 1; i++)
		{
			distance += distances[std::make_pair(cities[i], cities[i + 1])];
		}
		if (distance > max_distance)
		{
			max_distance = distance;
		}
		distance = 0;
	} while (std::next_permutation(cities.begin(), cities.end()));
	std::cout << max_distance;
}

