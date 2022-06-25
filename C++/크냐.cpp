#include <iostream>

using namespace std;

int main (void){
    int before, after;
    
    while(cin >> before >> after){
        if(before == 0 && after == 0) break;
        
        if(before > after) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
