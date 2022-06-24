#include <iostream>

using namespace std;

int main()
{
    int all[31] = {0, };
    
    for(int i = 0 ; i < 28 ; i++){
        int number;
        cin >> number;
        
        all[number] = 1;
    }
    
    for(int i = 1 ; i <= 30 ; i++){
        if(all[i] == 0) cout << i << endl;
    }

    return 0;
}
