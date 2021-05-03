#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0, add = 0;
    
    for(int i = 1 ; i < n+1 ; i++){
        add = 0;
        for(int j = i ; j < n+1 ; j++){
            add += j;
            if(add == n){answer++; break;}
            else if(add > n) break;
        }
    }
    
    return answer;
}