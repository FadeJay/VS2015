#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream input;
	ofstream output;
	string infile, outfile;
	cout << "������Ҫ���Ƶ��ļ�·��:" << endl;
	cin >> infile;
	cout << "���������ļ���·��:" << endl;
	cin >> outfile;
	input.open(infile.c_str(), ios::binary);
	output.open(outfile.c_str(), ios::binary);
	if (!input)
	{
		cerr << "error:can not open file:" << infile << endl;
		return -1;
	}
	if (!input)
	{
		cerr << "error:can not create file:" << infile << endl;
		return -1;
	}
	//output << input.rdbuf();
	//cout << "���Ƴɹ�" << endl;
	const int BufferSize = 1024*1024*100;
	static char buffer[BufferSize];
	while (!input.eof())
	{
		memset(buffer, 0, sizeof(buffer));
		input.read(buffer, sizeof(buffer));
		output.write(buffer, sizeof(buffer));
	}
	output.close();
	input.close();
	cout << "success" << endl;
	return 0;
}