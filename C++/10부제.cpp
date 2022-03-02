#include <iostream>

using namespace std;

int main()
{
    int a = 0, answer = 0;
    
    cin >> a;
    
    for(int i = 0 ; i < 5 ; i++){
        int tmp = 0;
        cin >> tmp;
        
        if(tmp % 10 == a) answer++;
    }
    
    cout << answer;

    return 0;
}
