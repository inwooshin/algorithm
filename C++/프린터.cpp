#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int i = 0;
    auto max = max_element(priorities.begin(), priorities.end());
    
    for(i = 0 ; i < priorities.size() ; i++){
        max = max_element(max, priorities.end());
        if(*max == 0){max = priorities.begin();  max = max_element(max, priorities.end());}
        else if(*max < *max_element(priorities.begin(), max)){max = max_element(priorities.begin(), max);}
        if(max - priorities.begin() == location) break;
        *max = 0;
    }
    
    return i+1;
}

//stack을 사용한 것 
int solution(vector<int> priorities, int location) {
    int i = 0;
    stack<int> s;
    auto max = max_element(priorities.begin(), priorities.end());
    
    for(i = 0 ; i < priorities.size() ; i++){
        max = max_element(max, priorities.end());
        if(*max == 0){max = priorities.begin();  max = max_element(max, priorities.end());}
        else if(*max < *max_element(priorities.begin(), max)){max = max_element(priorities.begin(), max);}
        s.push(max - priorities.begin());
        if(s.top() == location) break;
        *max = 0;
    }
    
    return i+1;
}
