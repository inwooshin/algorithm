#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, max = 0, minus = 1001, minusI = 0, first = 0, allTime = 0;

    for(int i = 0 ; i < jobs.size() ; i++){
        if(max < jobs[i][0]) max = jobs[i][0];
        if(minus > jobs[i][0]){ 
            minus = jobs[i][0];
        }
    }
    
    vector<priority_queue<int, vector<int>, greater<int>>> pq(max + 1);
    
    for(int i = 0 ; i < jobs.size() ; i++){
        pq[jobs[i][0]].push(jobs[i][1]);
    }
    
    allTime += pq[minus].top() + minus;
    answer += allTime - minus;
    pq[minus].pop();
    
    for (int i = 0; i < jobs.size() - 1; i++) {
        int min = 1001, minI = 0, getMin = 0;
        for (int j = 0; j < allTime; j++) {
            if(j > max) break;
            if (pq[j].size() != 0) {
                int tmp = pq[j].top();
                if (min > tmp) {
                    min = tmp;
                    minI = j;
                    getMin = 1;
                }
            }
        }
        if(getMin == 0){
            for (int j = 0; j <= max; j++) {
                if (pq[j].size() != 0) {
                    min = pq[j].top();
                    minI = j;
                    allTime = minI;
                    getMin = 1;
                    break;
                }
            }
        }
        if(getMin){
            allTime += pq[minI].top();
            pq[minI].pop();
            answer += allTime - minI;
        }
    }
    
    return answer / jobs.size();
}