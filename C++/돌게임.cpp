#include <iostream>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    int i = 0;
    for(; true ; i++){
        if(N >= 3) N -= 3;
        else N -= 1;
        
        if(N == 0) break;
    }

    if(i % 2 == 0){
        cout << "SK";
    }
    else cout << "CY";
    
    return 0;
}
