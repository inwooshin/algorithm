#include <iostream>

using namespace std;

int main()
{
    int N, answer = 0;
    
    cin >> N;
    
    for(int i = 1 ; i <= N ; i++){
        int tmp;
        
        cin >> tmp;
        
        if(i != tmp) answer++;
    }
    
    cout << answer;
    
    return 0;
}
