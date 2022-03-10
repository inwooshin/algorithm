#include <iostream>

using namespace std;

int main()
{
    int n, answer = 0;
    
    cin >> n;
    
    for(int i = 0 ; i < 5 ; i++){
        int tmp = n % 10;
        n /= 10;
        
        answer += tmp * tmp * tmp * tmp * tmp;
    }
    
    cout << answer;

    return 0;
}
