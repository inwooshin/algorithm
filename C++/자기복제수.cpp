#include <iostream>

using namespace std;

int main()
{
    int N, Number;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        
        cin >> Number;
        int j = 0;
        
        for(j = 1000 ;  ; j /= 10){
            if(Number / j != 0) break;
        }
        
        j *= 10;
        
        if ((Number * Number) % j == Number) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

    return 0;
}
