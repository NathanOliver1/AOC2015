#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <limits>

struct Ingredient
{
	std::string name;
	int capcity;
	int durability;
	int flavor;
	int texture;
	int calories;
	Ingredient() {}
	Ingredient(std::string name_, int cap, int dur, int flav, int tex, int cal) :
		name(name_), capcity(cap), durability(dur), flavor(flav), texture(tex), calories(cal) {}
};

int main()
{
	int seconds = 2503;
	std::ifstream fin("test.txt");
	std::vector<Ingredient> ingredients;
	std::string eater;
	Ingredient temp;
	while (fin >> temp.name >> eater >> temp.capcity >> eater >> eater >> temp.durability
		>> eater >> eater >> temp.flavor >> eater >> eater >> temp.texture >> eater >> eater >> temp.calories)
	{
		ingredients.push_back(temp);
	}
	int max_score = 0;
	for (int i = 100; i >= 0; i--)
	{
		for (int j = 100 - i; j >= 0; j--)
		{
			for (int k = 100 - i - j; k >= 0; k--)
			{
				for (int l = 100 - i - j - k; l >= 0; l--)
				{
					int cap = ingredients[0].capcity * i + ingredients[1].capcity * j + ingredients[2].capcity * k + ingredients[3].capcity * l;
					int dur = ingredients[0].durability * i + ingredients[1].durability * j + ingredients[2].durability * k + ingredients[3].durability * l;
					int flav = ingredients[0].flavor * i + ingredients[1].flavor * j + ingredients[2].flavor * k + ingredients[3].flavor * l;
					int tex = ingredients[0].texture * i + ingredients[1].texture * j + ingredients[2].texture * k + ingredients[3].texture * l;
					int max = (cap < 0 ? 0 : cap) * (dur < 0 ? 0 : dur) * (flav < 0 ? 0 : flav) * (tex < 0 ? 0 : tex);
					if (max > max_score)
						max_score = max;
				}
			}
		}
	}
	std::cout << max_score;
}
