#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

//queue 를 사용하지 않고 푼 것! 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp, max = 101, count = 0;
    vector<int> answer;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
        if(i == 0){max = tmp;}
        if(max >= tmp) count++;
        else{
            max = tmp;
            answer.push_back(count);
            count = 1;
        }
        if(i == progresses.size() - 1){answer.push_back(count);}
    }
    return answer;
}

// 7 4 2 9 -> 3 1
//순차적으로 대소의 관계를 나타내고 적은 값을 저장할 때 자기의 값을 
//vector 에 push 해주고 answer.back()이 자신을 참조리턴하기 때문에 ++를 사용해서
//더해준다! 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp, max = 101, count = 0;
    vector<int> answer;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
        if(answer.empty() || max < tmp) answer.push_back(1);
        else answer.back()++;
        
        if(max < tmp) max = tmp;
    }
    return answer;
}

//queue 를 사용하고 푼 것 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp, max = 101, count = 0;
    vector<int> answer;
    deque<int> q;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
        q.push_back(tmp);
        if(i == 0) continue;
        if(q.front() >= tmp){
            q.pop_back();
            count++;
        }
        else{
            q.pop_front();
            count++;
            answer.push_back(count);
            count = 0;
        }
        if(i == progresses.size() - 1 && !q.empty()){
            count++;
            answer.push_back(count);
        }
    }
    return answer;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp;
    vector<int> answer;
    deque<int> q;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
		if(answer.empty() || q.front() < tmp){
			q.push_back(tmp);
            answer.push_back(1);
        }
        else answer.back()++;
        //참조 형식으로 리턴하기 때문에 값이 변경되는 것이다! 
        
        if(q.front() < tmp){
        	q.pop_front();
		}
    }
    return answer;
}
