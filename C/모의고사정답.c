#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    vector<int> score(3);
    int len = answers.size(), high = 0;
    
    for(int i = 0; i < len ; i++){
        if(answers[i] == one[i % 5])  score[0]++;
        if(answers[i] == two[i % 8]) score[1]++;
        if(answers[i] == three[i % 10]) score[2]++;
    }
    
    
    
    for(int i = 0 ; i < 3 ; i++){
        if(high <= score[i]) high = score[i];
    }
    
    if(score[0] == high) answer.push_back(1);
    if(score[1] == high) answer.push_back(2);
    if(score[2] == high) answer.push_back(3);
    
    return answer;
}
