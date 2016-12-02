#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <limits>
#include <cctype>
#include <unordered_map>
#include <functional>

int getOnNeighbors(const std::vector<std::vector<char>> & lights, int row, int col);

int main()
{
	std::vector<std::vector<char>> lights(100);
	std::vector<std::vector<char>> new_lights;
	char ch;
	std::ifstream fin("test.txt");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			fin >> ch;
			lights[i].push_back(ch);
		}
	}
	new_lights = lights;
	for (int times = 0; times < 100; times++)
	{
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int count = getOnNeighbors(lights, i, j);
				if (lights[i][j] == '#')
				{
					if (count == 2 || count == 3)
						new_lights[i][j] = '#';
					else
						new_lights[i][j] = '.';
				}
				else
				{
					if (count == 3)
						new_lights[i][j] = '#';
					else
						new_lights[i][j] = '.';
				}
			}
		}
		lights = new_lights;
	}
	int counter = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (lights[i][j] == '#')
				counter++;
	std::cout << counter;
}

int getOnNeighbors(const std::vector<std::vector<char>> & lights, int row, int col)
{
	int counter = 0;
	int start_row = (row == 0 ? row : row - 1);
	int end_row = (row == lights.size() - 1 ? row : row + 1);
	int start_col = (col == 0 ? col : col - 1);
	int end_col = (col == lights[row].size() - 1 ? col : col + 1);
	for (int i = start_row; i <= end_row; i++)
		for (int j = start_col; j <= end_col; j++)
			if (lights[i][j] == '#')
				if (!(i == row && j == col))
					counter++;
	return counter;
}

