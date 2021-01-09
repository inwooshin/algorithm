#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s_size = 0;
void my_strcpy(char * arr, const int* n1, const int* n2){
    char temp[8] = "";
    sprintf(temp, "%d", *n1);
    strcat(arr, temp);
    
    sprintf(temp, "%d", *n2);
    strcat(arr, temp);
}

int compare (const int * a, const int *b){
    char ab[9] = "";
    char ba[9] = "";
    char *ap = ab;
    char *bp = ba;
    
    my_strcpy(ab, a, b);
    my_strcpy(ba, b, a);
    s_size += strlen(ab);
    
    while(*ap == *bp && *ab != 0){
        if(*ap != *bp){
            return *ap > *bp ? -1 : 1;
        }
        ap++;
        bp++;
    }
    
    if(*ap == *bp){
        return 0;
    }
    return *ap > *bp ? -1 : 1;
}

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char * answer;
    
    qsort(numbers, numbers_len, sizeof(int), compare);
    
    if(*numbers == 0){
        answer = (char *) malloc(sizeof(char) * 2);
        answer[0] = '0';
        answer[1] = '\0';
        return answer;
    }
    
    answer = (char*)malloc(sizeof(char)* (s_size + 1));
    char* tmp = (char*)malloc(8);
    
    *answer = 0;
    
    size_t i;
    for( i = 0 ; i < numbers_len ; i++){
        sprintf(tmp,"%d", numbers[i]);
        strcat(&answer[i], tmp);
    }
    
    return answer;
}

int main (){
	int numbers[5] = {3,30,34,5,9};
	
	solution(numbers, 5);
}
