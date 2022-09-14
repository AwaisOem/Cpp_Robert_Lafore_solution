#include<iostream>
using namespace std;
int main()
{
		float f,c,temp;		
	cout <<"Enter 1 to convert temperature from Fahrenheit to Celsius "<<endl
	 <<"Enter 2 to convert temperature from Celsius to Fahrenheit: ";
	cin >>temp;	
	if(temp==1)
	{
		cout <<"\nEnter Temperature in Fahrenheit: ";
		cin >>f;
		float result = (f-32)*5/9;
		cout <<"\nIn Celsius that's "<<result;
	}
	else
	{
		cout <<"\nEnter Temperature in Celsius: ";
		cin >>c;
		float result = (c*9/5)+32;
		cout <<"\nIn Fahrenheit that's "<<result;
	}
	cout <<endl;
	return 0;
}
