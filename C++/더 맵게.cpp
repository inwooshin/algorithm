#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int i;
    
    //priority_queue<int, vector<int>, greater<int> > a(scoville.begin(), scoville.end());
    //으로 밑의 push for 문을 없애줄 수 있다! 
    priority_queue<int, vector<int>, greater<int> > a;
    
    for(int i = 0 ; i < scoville.size() ; i++){
        a.push(scoville[i]);
    }
    
    //계속 정렬해야하기 때문에 이게 최고의 알고리즘이다! 
    for(i = 0 ; a.top() < K; i++){
        if(a.size() > 1){
        int tmp = a.top();
        a.pop();
        a.push(tmp + a.top() * 2);
        a.pop();
        }
        else    return -1;
    }
    
    return i;
}
