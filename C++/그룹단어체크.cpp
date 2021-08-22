#include <iostream>
#include <string>

using namespace std;

int main (void){
    int all = 0, count;
    string a[100];
    
    cin >> count;
    
    for(int i = 0 ; i < count ; i++){
        cin >> a[i];
        char bef = a[i][0];
        int isRight = 1;
    
        for(int j = 0 ; j < a[i].size() ; j++){
            if(a[i][j] == bef) continue;
            if(a[i][j] <= bef){isRight = 0; break;}
            bef = a[i][j];
            
        }
        
        if(isRight != 0) all++;
    }
    
    cout << all;
}
