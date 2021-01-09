#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    double comp;
    
    for(int i = 1 ; i <= n ; i++){
        comp = ((double)n / i) - floor(((double)n / i));  
        if(comp == 0)  answer += i;
    }
    
    return answer;
}
