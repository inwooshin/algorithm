#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, tmp;
    int comLen = commands.size();
    
    for(int i = 0 ; i < comLen ; i++){
        tmp = array;
        sort(tmp.begin() + commands[i][0] - 1, tmp.begin() + commands[i][1]);
        answer.push_back(tmp[commands[i][0] + commands[i][2] - 2]);
    }
    
    return answer;
}
