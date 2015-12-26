#include<iostream>
#include<fstream>
#include<string>
using namespace std;
istream& in(istream&);
int main()
{
	string str;
	cout << "Please input file name:" << endl;
	cin >> str;
	ifstream infile(str.c_str());
	if (!infile)
	{
		cerr << "error : can not open input file :" << str << endl;
		return -1;
	}
	in(cin);
	return 0;
}
istream& in(istream& input)
{
	int ival;
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