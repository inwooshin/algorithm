#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
    int len = strlen(s);
    char* answer = (char*)malloc(len);
    strcpy(answer, s);
    char tmp;
    
    for(int i = 0 ; i < len ; i++){
        for(int j = i+1 ; j < len ; j++){
            if(answer[i] < answer[j]){
                tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }

    return answer;
}

// 이렇게도 풀 수 있습니다. 함수가 워낙 그지 같아서 매개변수를 주소로 갖고 오지
// 않으면 제대로 분별이 안될 수가 있다.
int compare (const void * a, const void * b){
    if(*(char *)a < *(char *)b) return 1;
    else if(*(char *)a > *(char *)b) return -1;
    else return 0;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요
    char* str = (char *)malloc(strlen(s));
    strcpy(str,s);
    
    qsort(str, strlen(s), 1, compare);

    return str;
}