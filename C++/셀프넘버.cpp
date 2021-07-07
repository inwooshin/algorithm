#include <stdio.h>
#include <math.h>

int d(){
    char check[10001] = {0,};
    
    for(int a = 1 ; a <= 10000; a++){
        int n = a;
        for(int i = 0 ; n <= 10000 ; i++){
            
            int tmp = n;
            
            for(int i = 0 ; n != 0 ; i++){
                tmp += n % 10;
                n /= 10;
            }
            
            n = tmp;
            
            if(n <= 10000)check[n] = 1;
        }
    }
    
    for(int i = 1 ; i < 10000 ; i++){
        if(check[i] == 0) printf("%d\n", i);
    }
    
    return 0;
}

int main (void){
    d();
}
