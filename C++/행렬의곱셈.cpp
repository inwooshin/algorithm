#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0 ; i < arr1.size() ; i++){
        vector<int> tmp;
        
        for(int j = 0 ; j < arr2[0].size() ; j++){
            int node = 0;
            for(int k = 0; k < arr2.size() ; k++){
                node += arr1[i][k] * arr2[k][j];
            }
            tmp.push_back(node);
            
        }
        answer.push_back(tmp);
    }
    return answer;
}