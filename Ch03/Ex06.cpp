#include<iostream>
using namespace std;
int main()
{
    int n=1;
    while(n!=0){
        cout << "Enter a number to calculate its factorial or 0 to end this program: ";
        cin>>n;
        int fac = 1;
        for(int i = 1; i<=n; i++){
        fac *=i;
        }
        cout << "The factorial of " << n << " is : " << fac << endl;
    }
    return 0;
}
