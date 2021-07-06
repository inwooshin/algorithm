#include <iostream>
#include <string>

using namespace std;

int main (void){
    
    string a;
    cin >> a;
    
    for(int j = 0 ; j < 26 ; j++){
        int find = 0;
        for(int i = 0 ; i < a.size() ; i++){
            if('a' + j == a[i]){ cout << i << " "; find = 1; break;}
        }
        if(find == 0) cout << -1 << " ";
    }
}