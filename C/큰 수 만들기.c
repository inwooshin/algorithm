#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(number), input;
    char* answer = (char*)malloc(len -k + 1);
    int maxi = -1;
    char max = 0;
    //printf("%d", max);
    for(int j = 0 ; j < len - k ; j++){
        //printf("%d ---\n", j+1);
        max = 0; 
        for(int i = maxi + 1; i <= k + j; i++){
            //printf("i : %d\n", i);
            if(max < number[i]){
                max = number[i];
                maxi = i;
            }
        }
        answer[j] = max;
        //printf("answer[%d] : %c, all : %d, max : %c, maxi : %d\n", j, answer[j], all, max, maxi);   
    }
    answer[len - k ] = '\0';
    
    return answer;
}
