#include<iostream>
#include<sstream>
#include<string>
using namespace std;
istream& in(istream& input);
int main()
{
	string line;
	cout << "input a line:" << endl;
	getline(cin, line);
	line += " ";
	istringstream steam(line);
	in(steam);
	return 0;
}
istream& in(istream& input)
{
	//int ival;
	string ival;
	while (input >> ival, !input.eof())
	{
		if (input.bad())
			throw runtime_error("IO stream corrupted");
		if (input.fail())
		{
			cerr << "bad data,try again";
			input.clear();
			input.ignore(200, ' ');
			continue;
		}
		cout << ival << '\t';
	}
	input.clear();
	return input;
}