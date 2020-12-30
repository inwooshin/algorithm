#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//피보나치 
int solution(int n) {
    int answer = 0;
    int* piv = (int *)malloc((n+1) * sizeof(int));
    piv[0] = 0; piv[1] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        piv[i] = (piv[i-1] + piv[i-2]) % 1234567;
    }
    
    answer = piv[n];
    printf("ans : %d", answer);
    
    return answer;
}
