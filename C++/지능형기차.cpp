#include <iostream>

using namespace std;

int main()
{
    int pOut = 0, pIn = 0, all = 0, max = 0;
    
    while(cin >> pOut >> pIn){
        all += (pIn - pOut);
        if(max < all) max = all;
    }
    
    cout << max;

    return 0;
}
