#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0 ; i < s.length(); i++){
        if(isupper(s[i])){
           answer += (s[i] - 'A' + n) % 26 + 'A';
        }
        else if(islower(s[i])){
            answer += (s[i] - 'a' + n) % 26 + 'a';
        }
        else answer += s[i];
    }
    
    return answer;
}
