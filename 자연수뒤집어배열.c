#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    
    int len;
    for(int i = 10 ; i >= 0 ; i--){
        if((n / (long long) pow(10, i)) != 0) {len = i+1; break;}
    }
    
    int* answer = (int*)malloc(len * sizeof(int)), div;
    
    for(int i = len - 1; i >= 0 ; i--){
        div = (n / (long long) pow(10, i));
        n = n - (pow(10, i) *div);
        answer[i] = div;
    } 
    
    return answer;
}
