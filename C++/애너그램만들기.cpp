#include <iostream>

using namespace std;

int main()
{
    int chA[28] = {0, }, chB[28] = {0, };
    int all = 0;
    string N, M;
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N.size() ; i++){
        chA[N[i] - 'a']++;
    }
    
    for(int i = 0 ; i < M.size() ; i++){
        if(chA[M[i] - 'a'] != 0) chA[M[i] - 'a']--;
        else chB[M[i] - 'a']++;
    }
    
    for(int i = 0 ; i < 26 ; i++){
        all += chA[i] + chB[i];
    }
    
    cout << all;

    return 0;
}
