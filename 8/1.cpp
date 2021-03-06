#include<iostream>
using namespace std;
istream& in(istream&);
int main()
{
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
		cout << ival <<'\t';
	}
	input.clear();
	/*while (input >> ival, !input.eof())
	{
		if (input.bad())
			throw runtime_error("IO stream corrupted");
		if (input.fail())
		{
			cerr << "bad data,try again" <<endl;
			//input.clear(istream::failbit);
			input.clear(istream::failbit^input.rdstate());
			input.clear();
			//input.sync();
			input.ignore(1024, ' ');
			//input.ignore();
			continue;
		}
		cout << ival <<endl;
	}*/
	/*input >> ival;
	if (input.fail())
	{
		cerr << "bad data,try again";
		input.clear(istream::failbit);
		continue;
	}*/
	return input;
}