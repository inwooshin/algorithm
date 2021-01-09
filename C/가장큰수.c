#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(numbers_len *4 +1);
    char* tmp = (char*)malloc(numbers_len *4 +1);
    *answer = 0;
    int len = 0, comp, max = 0, maxi, also, alsoi = 0,alsoCount= 0;
    char str = 0, a = 0;
    int* isCheck = (int *)malloc(numbers_len * sizeof(int));
    int* answerInt = (int *)malloc((numbers_len+1) * sizeof(int));
    memset(isCheck, 0, sizeof(int) * numbers_len);
    
    //printf("1");
    
    int j;
    int i;
    for( j = 0 ; j < numbers_len ; j++){
        for( i = 0 ; i < numbers_len ; i++){
            if(numbers[i] > 999) comp = numbers[i] / 1000;
            else if(numbers[i] > 99) comp = numbers[i] / 100;
            else if(numbers[i] > 9) comp = numbers[i] /10;
            else comp = numbers[i];
            
            
            if(max == comp && !isCheck[i]){
                if(numbers[i] > 999) {
                	also = numbers[i] - 1000;
					if(max < (also / 100)){
						also = comp; 
						alsoi = i;
					}
				}
				else if( numbers[i] > 99){
					also = numbers[i] - (100 * (numbers[i] / 100));
					if(max < (also / 10)){
						also = comp; 
						alsoi = i;
					}
				}
				else if( numbers[i] > 9){
					also = numbers[i] - (10 * (numbers[i] / 10));
					if(max < also){
						also = comp; 
						alsoi = i;
					}
				}
				else continue;
			}
            if(max < comp && !isCheck[i]) {max = comp; maxi = i;}
        }
        
        if(also == max && !isCheck[alsoi]){
        	alsoCount = 0;
        	isCheck[alsoi] = true;
        	max = 0;
        	answerInt[j] = numbers[alsoi];
			continue;
		}
        
        isCheck[maxi] = true;
        
        
        //_itoa(numbers[maxi],&a,1);
        answerInt[j] = numbers[maxi];
        max = 0;
    }
    int leng = 0;
    
    for(i = 0 ; i < numbers_len ; i++){
        sprintf(tmp,"%d", answerInt[i]);
        strcat(answer, tmp);
    }
    
    
	answer[numbers_len * 4] = '\0';
    
    return answer;
}
