#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0; answer[1] = 0;
    int len = strlen(s);
    double tmpin = 0;
    char* tmp = (char*)malloc(sizeof(char) * len);
    strcpy(tmp, s);
    int tmplen = strlen(tmp), tmpInt, once = 0;
    double div;
    int i, all;

    
    while(tmplen != 1){
        tmpin = 0;
        for( i = 0 ; i < tmplen ; i++){
            if(tmp[i] == '0')answer[1]++;
            else tmpin = tmpin + 1;
        }
        
        tmplen = 0;
        tmp = (char *)realloc(tmp,sizeof(char) * 19);
        memset(tmp, 0, 19);
        
        printf("tmpin : %f\n", tmpin);
        for(i = 18 ; i >= 0 ; i--){
            div = floor(tmpin / pow(2.0, i));
            if(!div && !once) continue;
            printf("%d, in\n", i);
			if(!once) all = i;
            once = 1;
        	printf("div : %f\n", div);
            if(div == 1) tmp[all - i] = '1';
            else tmp[all - i] = '0';
            printf("tmpin : %f\n", tmpin);
            tmpin = tmpin - div * pow(2.0, i);
            tmplen++;
        }
        //printf("tmplen : %d", tmplen);
        
        printf("\n\ntmp : %s\n\n", tmp);
        answer[0]++;
        once = 0; 
    }
    
    printf("%d %d", answer[0], answer[1]);
    return answer;
}

int main (void){
	char s[] = "110010101001";
	
	solution(s);
}
