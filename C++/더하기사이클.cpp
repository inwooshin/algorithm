#include <iostream>

using namespace std;

int main (void){
    
    int input, change = 0, i = 0;
    
    cin >> input;
    
    while(input != change){
        if(i == 0) change = input;
        if((change / 10) == 0){
            change *= 10;
        }
        
        int tmp_add = (change / 10) + (change % 10);

        change = (int)(change / 10) * 10 + (tmp_add % 10);
        i++;
    } 
    if(input == 0) cout << 1;
    else cout << i;
    
    return 0;
}
