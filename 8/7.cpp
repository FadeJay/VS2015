#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main()
{

	vector<string> str;
	string filename, s;
	cout << "input filename:" << endl;
	cin >> filename;
	ifstream infile(filename.c_str());
	if (!infile)
	{
		cerr << "error:can not open file:" << filename << endl;
		return -1;
	}
	while (infile >> s)
		str.push_back(s);
	infile.close();
	for (vector<string>::const_iterator it = str.begin();it != str.end();++it)
		cout << *it << endl;
	return 0;
}
