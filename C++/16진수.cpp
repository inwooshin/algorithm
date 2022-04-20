#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int all = 0;
    string sentence;
    
    cin >> sentence;
    
    for(int i = 0 ; i < sentence.size() ; i++){
        
        int hex = 0;
        if(sentence[i] >= 'A' && sentence[i] <= 'F'){
            hex = sentence[i] - 'A' + 10;
        }
        if(sentence[i] >= '0' && sentence[i] <= '9'){
            hex = sentence[i] - '0';
        }
        
        hex *= pow(16, sentence.size() - 1 - i);
        
        all += hex;
    }
    
    cout << all;
    
    return 0;
}