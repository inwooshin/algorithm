#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max = 0, less = 0;
    
    for(int i = 0 ; i < sizes.size() ; i++){
        if(sizes[i][0] >= sizes[i][1]){
            if(sizes[i][0] > max){
                max = sizes[i][0];
            }
            if(sizes[i][1] > less){
                less = sizes[i][1];
            }
        }
        else{
            if(sizes[i][1] > max){
                max = sizes[i][1];
            }
            if(sizes[i][0] > less){
                less = sizes[i][0];
            }
        }
    }
    
    return max * less;
}