#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ofstream& open_file(ofstream &out, const string &file);
ifstream& open_file(ifstream &in, const string &file);
istream& in(istream& input);
int main()
{
	string filename;
	cout << "Please input filename" << endl;
	cin >> filename;
	ifstream infile;
	if (!open_file(infile, filename))
	{
		cerr << "error:can not open file:" << filename << endl;
		return -1;
	}
	in(infile);
	infile.close();
	return 0;
}
ofstream& open_file(ofstream &out, const string &file)
{
	out.close();
	out.clear();
	out.open(file.c_str());
	return out;
}
ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
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