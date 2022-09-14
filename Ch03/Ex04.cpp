#include<iostream>
using namespace std;
int main()
{
	float n1,n2;
	char opr, ch;	
	do {
		cout <<"\nEnter first number, operator, second number: ";
		cin >>n1 >>opr >>n2;	
		switch(opr)
		{
			case '+':
			cout <<"\nAnswer = " <<n1+n2;
			break;
			
			case '-':
			cout <<"\nAnswer = " <<n1-n2;
			break;
			
			case '*':
			cout <<"\nAnswer = " <<n1*n2;
			break;
			
			case '/':
			cout <<"\nAnswer = " <<n1/n2;
			break;
			
			default:
			cout <<"\nInvalid Input! ";
		}
		cout <<"\n\nDo You Want Another, Press(y/n): ";
		cin >>ch;
	}while(ch != 'n');
	return 0;
}
