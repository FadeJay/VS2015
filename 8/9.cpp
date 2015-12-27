#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
	ostringstream format_message;
	int val1 = 250, val2 = 1024;
	format_message << "val1: " << val1 << "\n" << "val2: " << val2<< "\n";
	istringstream input_istring(format_message.str());
	string dump,dump1;
	//input_istring >> dump >> val1 >> dump1 >> val2;
	input_istring >> dump >> val2 >> dump1 >> val1;
	//cout << dump << endl;
	cout << dump << "  " << dump1 << endl;
	cout << val1 << "  " << val2 << endl;
	return 0;
}