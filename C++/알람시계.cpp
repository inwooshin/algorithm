#include <iostream>

using namespace std;

int main (void){
    int a, b;

    cin >> a >> b;

    b = b - 45;

    if(b < 0){
        b = 60 + b;
        a--;
    }
    if(a < 0){
        a = 23;
    }

    cout << a << ' ' << b;

    return 0;
}