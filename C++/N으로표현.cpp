#include <vector>
#include <unordered_set>

using namespace std;

int getNN(int N, int num){
    int tmp = N;
    
    for(int i = 0 ; i < num ; i++){
        tmp = tmp * 10 + N;
    }
    
    return tmp;
}

int solution(int N, int number) {
    //Dynamic Programming
    
    if(N == number) return 1;
    
    int answer = 0;
    vector<unordered_set<int>> set(8);
    
    set[0].insert(N);
    
    for(int i = 1 ; i < 8 ; i++){
        for(int j = 0 ; j < i ; j++){
            for(int k = 0 ; k < i ; k++){
                if(k + j != i - 1) continue;
                
                for(int a : set[j]){
                    for(int b : set[k]){
                        set[i].insert(a + b);
                        set[i].insert(a * b);
                        if(a - b > 0)
                            set[i].insert(a - b);
                        if(a / b > 0)
                            set[i].insert(a / b);
                    }
                }

            }
        }
        
        set[i].insert(getNN(N, i));
        if(set[i].count(number)) return i + 1;
    }
    
    return -1;
}