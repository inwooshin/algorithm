#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    double all, own = x;
    
    while( x != 0){
        all += x%10;
        x /= 10;
    }
    
    if((own / all) == floor(own/all)) return true;
    else return false;
}
