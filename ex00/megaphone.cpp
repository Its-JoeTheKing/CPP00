#include <iostream>

int main(int ac, char *argv[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string mega = argv[i];
		for (size_t j = 0; j < mega.size(); j++)
		{
			std::cout << (char)std::toupper(mega[j]);
		}
	}
	std::cout << "\n";
	return 0;
}
