#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    int len = s.length();
    int number = 0;
    bool answer = true;
    
    for(int i = 0 ; i < len ; i++)
        if(isdigit(s[i])) number++;
    printf("%d %d", len, number);
    if((len == 4 || len == 6) && (len == number)) 
        return true;
    else return false;
    
    return 0;
}
