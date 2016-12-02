#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <limits>

struct Aunt
{
	int children;
	int cats;
	int samoyeds;
	int pomeranians;
	int akitas;
	int vizslas;
	int goldfish;
	int trees;
	int cars;
	int perfumes;
};

bool operator==(const Aunt& lhs, const Aunt& rhs)
{
	bool ret = true;
	if (lhs.children != -1 && rhs.children != -1)
		ret &= (lhs.children == rhs.children);
	if (lhs.samoyeds != -1 && rhs.samoyeds != -1)
		ret &= (lhs.samoyeds == rhs.samoyeds);
	if (lhs.pomeranians != -1 && rhs.pomeranians != -1)
		ret &= (lhs.pomeranians == rhs.pomeranians);
	if (lhs.akitas != -1 && rhs.akitas != -1)
		ret &= (lhs.akitas == rhs.akitas);
	if (lhs.vizslas != -1 && rhs.vizslas != -1)
		ret &= (lhs.vizslas == rhs.vizslas);
	if (lhs.goldfish != -1 && rhs.goldfish != -1)
		ret &= (lhs.goldfish == rhs.goldfish);
	if (lhs.trees != -1 && rhs.trees != -1)
		ret &= (lhs.trees == rhs.trees);
	if (lhs.cars != -1 && rhs.cars != -1)
		ret &= (lhs.cars == rhs.cars);
	if (lhs.perfumes != -1 && rhs.perfumes != -1)
		ret &= (lhs.perfumes == rhs.perfumes);
	return ret;
}

int main()
{
	Aunt find{ 3,7,2,3,0,0,5,3,2,1 };
	std::ifstream fin("test.txt");
	std::vector<Aunt> aunts;
	std::string line;
	while (std::getline(fin, line))
	{
		std::stringstream ss(line);
		std::getline(ss, line, ':'); 
		std::string type, eater;
		int value;
		Aunt temp{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
		while (ss >> type >> value)
		{
			if (type == "children:")
				temp.children = value;
			if (type == "cats:")
				temp.cats = value;
			if (type == "samoyeds:")
				temp.samoyeds = value;
			if (type == "pomeranians:")
				temp.pomeranians = value;
			if (type == "akitas:")
				temp.akitas = value;
			if (type == "vizslas:")
				temp.vizslas = value;
			if (type == "goldfish:")
				temp.goldfish = value;
			if (type == "trees:")
				temp.trees = value;
			if (type == "cars:")
				temp.cars = value;
			if (type == "perfumes:")
				temp.perfumes = value;
			ss >> eater;
		}
		aunts.push_back(temp);
	}
	int spot;
	for (std::size_t i = 39; i < aunts.size(); i++)
	{
		if (aunts[i] == find)
			spot = i;
	}
	std::cout << spot + 1;
}

