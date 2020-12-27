#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    char* brString = (char *)malloc(strlen(s));
    *brString= 0;
    int insult = 0, len = strlen(s);
    
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == '(') brString[insult++] = '(';
        else if(s[i] == ')'){
            if(insult < 1)  return false;
            else insult--;
        }
    }
    
    if(insult){
        return false;
    }
    
    return true;
}
