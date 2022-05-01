
#include <iostream>

using namespace std;

int main()
{
    int alpha[26] = {0,};
    string S;
    
    cin >> S;
    
    for(int i = 0 ; i < S.size() ; i++){
        alpha[S[i] - 'a']++;
    }
    
    for(auto i : alpha){
        cout << i << " ";
    }

    return 0;
}
