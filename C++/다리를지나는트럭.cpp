#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, all = 0, tmp;
    vector<int> count;
    stack <int> s, pass;
    queue <int> q;
    
    for(int i = 0 ; i < truck_weights.size(); i++){
        s.push(truck_weights[i]);
    }
    
    while(pass.size() != truck_weights.size()){
        if(!s.empty() && all + s.top() <= weight){
            tmp = s.top();
            s.pop();
            q.push(tmp);
            all += tmp;
            count.push_back(0);
        }
        for(int j = 0 ; j < count.size() ; j++){
            count[j]++;
            if(count[j] == bridge_length){
                tmp = q.front();
                q.pop();
                pass.push(tmp);
                all -= tmp;
            }
        }
        answer++;
    }
        
    
    return ++answer;
}
