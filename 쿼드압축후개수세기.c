#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int * answer;
int try = 0;

int quadTree(int **arr, size_t rowsStart, size_t colsStart, size_t size){
    //printf("try : %d\n", try++);
    int all = 0;
    int i , j; 
    for(i = rowsStart ; i < rowsStart + size; i++){
        for( j = colsStart; j < colsStart + size; j++){
            all += arr[i][j];
        }
    }
    
    //printf("all = %d, every : %d, arr_rows : %d, arr_cols : %d, rs : %d, cs : %d\n", all, ((arr_rows- rowsStart) * (arr_cols- colsStart)), arr_rows, arr_cols, rowsStart, colsStart);
    
    if(all == (size * size)){
        answer[1]++;
        //printf("1 add\n");
        return 0;
    }
    else if(all == 0){
        answer[0]++;
        //printf("0 add\n");
        return 0;
    }
    
	quadTree(arr, rowsStart, colsStart, size/ 2);
	quadTree(arr, rowsStart, colsStart + size /2, size / 2);
	quadTree(arr, rowsStart + size/ 2, colsStart, size / 2);
	quadTree(arr, rowsStart + size/ 2, colsStart + size /2, size / 2);
    
    
    return 0;
}

// arr_rows는 2차원 배열 arr의 행 길이, arr_cols는 2차원 배열 arr의 열 길이입니다.
int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0; answer[1] = 0;
    quadTree(arr, 0, 0, arr_rows);
    
    return answer;
}
