#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::stod;
using std::sort;
using std::fixed;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		if (line.empty())
		{
			continue;
		}
		istringstream iss(line);
		string temp;
		vector<double> my_numbers;
		// Convert strings to numbers and load into vector
		while (getline(iss, temp, ' '))
		{
			double number = stod(temp);
			my_numbers.push_back(number);
		}

		// Sort and print numbers with a precision of 3
		sort(my_numbers.begin(), my_numbers.end());
		cout.precision(3);
		cout << fixed;
		for (auto& n: my_numbers)
		{
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}