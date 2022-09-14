#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	char ch;
	int n=0;
	cout <<"Enter a number: ";
	for(int i=1; i<=6; i++)
	{
		ch=getche();
		n=(n*10)+ch-'0';
	}
	cout <<"\nNumber is "<<n << endl;
	return 0;
}
