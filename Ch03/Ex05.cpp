#include <iostream>
using namespace std;
int main()
{
    for(int i = 1; i<=20; i++) {
        for(int j = 1; j<=20-i; j++) {
            cout << " ";
        }
        for(int k = 1; k<=i*2-1; k++) {
            cout << "X";
        }
        cout << "\n";
    }
    return 0;
}
