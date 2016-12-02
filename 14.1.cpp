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
	std::string name, eater;
	int speed, go, stop;
	std::string winner;
	int max_distance = 0;
	int seconds = 2503;
	while (fin >> name >> eater >> eater >> speed >> eater >> eater >> go >> eater >> eater >> eater >> eater >> eater >> eater >> stop >> eater)
	{
		int steps = seconds / (go + stop);
		int distance = steps * speed * go;
		if (steps * (go + stop) < seconds)
		{
			if (seconds - steps * (go + stop) < go)
				distance += (seconds - steps * (go + stop)) * speed;
			else
				distance += speed * go;
		}
		if (distance > max_distance)
		{
			max_distance = distance;
			winner = name;
		}
	}
	std::cout << max_distance;
}

