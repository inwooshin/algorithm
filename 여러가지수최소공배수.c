#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 0, count = 0;
    long long i;

    for(i = 1 ; i < 1000000000 ; i++){
        for(int j = 0 ; j < arr_len ; j++){
            if(!(i % arr[j])) count++;
            else break;
        }
        if(count == arr_len) break;
        count = 0;
    }

    answer = i;

    return answer;
}
