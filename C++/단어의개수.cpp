#include <iostream>
#include <string>

using namespace std;

int main (void){
    
    string a;
    int i = 0;
    
    for(; true; i++){
        string a;
        
        cin >> a;
        
        if(a.empty() == 1) break;
    }
    
    cout << i;
}