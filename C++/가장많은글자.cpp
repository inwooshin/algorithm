#include <iostream>

using namespace std;

int main()
{
    int ch[27] = {0,}, max = 0;
    string input;
    
    while(cin >> input){
        for(int i = 0 ; i < input.size() ; i++){
            ch[input[i] - 'a']++;
            
            if(ch[input[i] - 'a'] > max){
                 max = ch[input[i] - 'a'];
            }
        }
    }
    
    for(int i = 0 ; i < 27 ; i++){
        if(ch[i] == max) cout << (char)(i + 'a');
    }

    return 0;
}
