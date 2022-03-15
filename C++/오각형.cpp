#include <iostream>

using namespace std;

int main()
{
    int N, add = 2, 
         answer = 5;
    
    cin >> N;
    
    for(int i = 0 ; i < N - 1; i++){
        answer += 7 + (3 * i);
        answer %= 45678;
    }
    
    cout << answer;

    return 0;
}
