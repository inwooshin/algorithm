#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = 0;
    long long sq = sqrt(n);
    float sqr = sqrt(n);
    
    if(!(sqr - sq)) answer = (sq+1) * (sq+1);
    else answer = -1;
    
    return answer;
}
