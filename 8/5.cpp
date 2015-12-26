#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	int s;
	string filename;
	vector<string> files;
	cout << "input filenames:(Ctrl+z to end)" << endl;
	while (cin >> filename)
		files.push_back(filename);
	//files.push_back("test.txt");
	vector<string>::const_iterator it = files.begin();
	ifstream input;
	while (it != files.end())
	{
		input.open(it->c_str());
		if (!input)
		{
			cerr << "error:can not open file name:" << *it << endl;
			input.clear();
			++it;
			//continue;
		}
		else
		{
			while (input >> s)
				cout << s << endl;
			input.close();
			input.clear();
			++it;
		}
	}
	return 0;
}