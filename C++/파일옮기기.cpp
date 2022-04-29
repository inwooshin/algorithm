
#include <iostream>

using namespace std;

int main()
{
    int apple_A, orange_B, apple_C, orange_D;
    
    cin >> apple_A >> orange_B;
    cin >> apple_C >> orange_D;
    
    if(apple_A + orange_D > apple_C + orange_B)
        cout << apple_C + orange_B;
    else 
        cout << apple_A + orange_D;

    return 0;
}
