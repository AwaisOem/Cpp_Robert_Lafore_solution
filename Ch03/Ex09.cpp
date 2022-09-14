#include<iostream>
using namespace std;
int main()
{
	int guests, chairs, temp=1;
	cout <<"\nEnter the number of guests: ";
	cin >>guests;
	cout <<"\nEnter the number of chairs: ";
	cin  >>chairs;

	if(guests>chairs)
	{
		for(int i=1; i<=chairs; i++)
		{
			temp *= guests;
			--guests;
		}
	}
	cout <<"\nNumber of possible arrangements are: " <<temp;

	return 0;
}
