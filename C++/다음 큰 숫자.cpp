#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, tmp = n, own = 0, count = 0;
    
    while(tmp != 0){
        if(tmp % 2) own++;
        tmp /= 2;
    }
    
    for(n = n+1; true ; n++){
        tmp = n;
        count = 0;
        while(tmp != 0){
            if(tmp % 2) count++;
            tmp /= 2;
        }
        if(count == own){answer = n; break;}
    }
    
    return answer;
}
