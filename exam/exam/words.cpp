#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<conio.h>
#define in_file "data.txt"//input file name
#define out_file "result.txt"//output file name
using namespace std;
void inputwords(int&, int&);
void outputwords(int, int);
ifstream ins;// associates ins as an input stream
ofstream outs;// associates outs as an output stream
int letters=0;
int words=0;
char ch;

int main()
{
	ins.open(in_file);// associates ins as an input stream
	outs.open(out_file);// associates outs as an output stream

	bool charcheck;
	inputwords(letters, words);
	outputwords(letters, words);

	ins.close();// closing input file
	outs.close();// closing output file

	return 0;

}

bool charcheck (char c)
{
	if ((c >='a' && c <= 'z') || ((c >= 'A') && (c < 'Z')))
		return 1;
	else
		return 0;
}


void inputwords(int& letters, int& words)
{
	while(!ins.eof())
	{
		ins.get(ch);
		if (charcheck(ch))
		{
			letters++;
		}

		if((ch==' ')||(ch=='.')||(ch=='\n'))
		{
			words++;
		}

		ins.get(ch);
	}
}

void outputwords(int letters, int words)
{
	outs<<ch<<" has "<<letters<<endl;
	outs<<"There are "<<words<<" words."<<endl;
}