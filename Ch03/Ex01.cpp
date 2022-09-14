#include<iostream>
using namespace std;
#include<iomanip>
int main()
{
    int n, i, j, m=1;

    cout <<"Enter a Number For Multiplication: ";
    cin >>n;
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=10; j++)
        {
            cout <<setw(6) <<n*m++ <<"  ";
        }
        cout <<endl;
    }
    return 0;
}
