#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0, div;
    
    for(int i = 8 ; i >= 0 ; i--){
        div = n / pow(10, i);
        n = n - (pow(10, i)*div);
        answer += div;
    }
        
    return answer;
}
