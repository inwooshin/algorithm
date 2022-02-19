#include <iostream>

using namespace std;

int main()
{
    //N마리의 새
    
    long long N, answer = 0;
    
    cin >> N;
    
    for(int i = 1 ; N != 0 ; i++){
        if(N < i){ 
            i = 1;
        }
        
        N -= i;
        answer++;
    }
    
    cout << answer;
    
    return 0;
}
