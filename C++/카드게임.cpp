#include <iostream>

using namespace std;

int main()
{
    int tmp, answer = 0;
    
    while(cin >> tmp)
        answer += tmp;
    
    cout << answer;

    return 0;
}
