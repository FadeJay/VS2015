#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
	string filename,line,word;
	vector<string> str;
	cout << "input the file name:" << endl;
	cin >> filename;
	ifstream infile(filename.c_str());
	if (!infile)
	{
		cerr << "error:can not open the file:" << filename << endl;
		return -1;
	}
	while (getline(infile, line))
		str.push_back(line);
	infile.close();
	for (vector<string>::const_iterator it = str.begin();it != str.end();++it)
	{
		istringstream steam(*it);
		while (steam >> word)
			cout << word << "\t";
		steam.clear();
	}
	return 0;
}