#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    int sum = 0, add = 1, i = 0, j = 0, k = 0, all = n * (n+1) / 2, count = 0, first = 0, second = 0, own = n;
    
	if( n == 1) {answer[0] = 1; printf("%d", answer[0]); return answer;}
    // 0 1 3 6 10
    for(;add < all;){
        //0 2 5 9
        if(count == 0)
    		for(i = 0 ; i < n ; i++){
   	 			if(i == 0) {
					answer[0] = 1;
					continue;
				}
				answer[first + i] = ++add;
				first = first + i;
			}
    	else{
        	for(i = 0; i < n; i++){
				answer[first] = ++add;
				first = first + 2 * count + i + 1;
				printf("first : %d, add : %d\n", first, add);
        	}
        	first = first - 2 * count -i;
		}
        	
        n--;
        int m;
        printf("1 : ");
   		for(m = 0 ; m < all ; m++)
	 		printf("%d ", answer[m]); 
	 		printf("\n");
	
        for(j = 0; j < n ; j++){
            answer[first + j + 1] = ++add;
        }
        printf("2 : ");
   		for(m = 0 ; m < all ; m++)
	 		printf("%d ", answer[m]); 
	 		printf("\n");
        n--;
        second = first + j;
        //14 9 5 2 0  
        for(k = 0; k < n ; k++){
            answer[second - (own - count - k)] = ++add;
            second = second - (own - count - k);
        }
        printf("3 : ");
        for(m = 0 ; m < all ; m++)
	 		printf("%d ", answer[m]); 
	 		printf("\n");
        n--;
        count++;
        first = second + 2 * count;
    	//printf("first : %d\n", first);
		}
    
            
    //3n - 3 이 2 다음에 올 수이다.
    return answer;
}

int main (void){
	solution(1);
	printf("\n");
	solution(4);
	printf("\n");
	solution(5);
	printf("\n");
	solution(6);
	printf("\n");
}
