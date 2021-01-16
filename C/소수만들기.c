#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* PrimeArray;

void Eratos(int n)
{
	PrimeArray = (bool *)malloc(sizeof(bool) * (n+1));
    
	for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
			    PrimeArray[j] = false;
	}
    
    return ;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0, cmp;
    int j = 0,k = 1, l = 2;
    
    Eratos(3000);
    
    while(j != nums_len - 2){
        cmp = nums[j] + nums[k] + nums[l];
        if(PrimeArray[cmp]) answer++;
        if(l < nums_len - 1){l++; continue;}
        if(k == nums_len - 2){
            j++;
            k = j + 1;
            l = k + 1;
            continue;
        }
        if(l == nums_len - 1){
            k++;
            l = k + 1;
            continue;
        }
    }
    
    return answer;
}
