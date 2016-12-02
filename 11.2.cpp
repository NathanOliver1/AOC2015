#include<iostream>
#include <string>

void incrementString(std::string&);
bool hasTwoPairs(const std::string&);
bool hasBadLetter(const std::string&);
bool HasSequence(const std::string&);

int main()
{
	std::string password = "vzbxxyzz";
	incrementString(password);
	bool done = false;
	do
	{
		if (hasTwoPairs(password) && !hasBadLetter(password) && HasSequence(password))
			done = true;
		else
			incrementString(password);
	} while (!done);
	std::cout << password;
}

void incrementString(std::string& word)
{
	for (auto it = word.rbegin(); it != word.rend(); ++it)
	{
		if (*it == 'z')
		{
			*it = 'a';
		}
		else
		{
			(*it)++;
			break;
		}
	}
}

bool hasTwoPairs(const std::string& word)
{
	char first = 0, previous = 0;
	int counter = 0, pair_count = 0;
	for (auto e : word)
	{
		if (e == previous)
		{
			counter++;
		}
		if (e != previous)
		{
			if (counter)
			{
				if (first == 0)
				{
					first = previous;
					pair_count++;
				}
				else if (first != e && first != previous)
				{
					pair_count++;
				}
				counter = 0;
			}
			previous = e;
		}
	}
	if (word[word.size() - 1] == word[word.size() - 2])
		pair_count++;
	return pair_count >= 2;
}

bool hasBadLetter(const std::string& word)
{
	return word.find("iol", 0) != std::string::npos;
}

bool HasSequence(const std::string& word)
{
	for (std::size_t i = 0; i < word.size() - 2; i++)
	{
		if (word[i] + 1 == word[i + 1] && word[i + 1] + 1 == word[i + 2])
			return true;
	}
	return false;
}