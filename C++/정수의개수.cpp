#include <iostream>

using namespace std;

int main()
{
    int answer = 1;
    string N;
    
    cin >> N;
    
    for(int i = 0 ; i < N.size() ; i++){
        if(N[i] == ',') answer++;
    }
    
    cout << answer;
    
    return 0;
}
