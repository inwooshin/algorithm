#include <iostream>

using namespace std;

int main()
{
    int computer[101] = {0,}, N = 0, sit = 0, answer = 0;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> sit;
        if(computer[sit] == 0 ){
            computer[sit] = 1;
        }
        else answer++;
    }
    
    cout << answer;
    
    return 0;
}
