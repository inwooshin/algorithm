#include <iostream>

using namespace std;

int main()
{
    int N, M, max = 0, answer = 0;
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        int tmp = 0;
        cin >> tmp;
        
        if(max < tmp) max = tmp;
        
    }
    
    answer = max;
    max = 0;
    
    for(int i = 0 ; i < M ; i++){
        int tmp = 0;
        cin >> tmp;
        
        if(max < tmp) max = tmp;
    }
    
    answer += max;

    cout << answer;

    return 0;
}
