#include <iostream>
using std::cout;
using std::cin;
using std::string;

string ToUpper(string str)
{
	if (str.length() < 1)
		return "";
	char p[str.length()];
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			p[i] = str[i] - 32;
		else
			p[i] = str[i];
	}
	return p;
}

int main(int ac, char *argv[])
{
	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		cout << ToUpper(argv[i]);
	}
	cout << "\n";
	return 0;
}
