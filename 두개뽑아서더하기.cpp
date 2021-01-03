#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int len = numbers.size(), add = 0;
    vector<bool> count(200, false);
    
    for(int i = 0 ; i < len ; i++){
        for(int j = i + 1 ; j < len ; j++){
            add = numbers[i] + numbers[j];
            if(count[add] == false){
                answer.push_back(add);
                count[add] = true;
            }
        }
    }
    sort(answer.begin(), answer.end());
     
    return answer;
}
