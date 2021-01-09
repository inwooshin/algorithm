#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    
    long long a = num;
    while(a != 1){
        if(a % 2 == 0) a = a/ 2;
        else a = a * 3 + 1;
        ++answer;
        if(answer >499) return -1;
    }
    
    return answer;
}
