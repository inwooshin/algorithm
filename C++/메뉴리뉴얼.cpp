#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> match; 

void combination(int n, int count, int j, vector<int>& check, vector<char>& orders){
    string ins = "";
    
    if(count == n){
        for(int i = 0 ; i < orders.size() ; i++)
            if(check[i]){
                ins += orders[i];
            }
        
        if(match.find(ins) == match.end()) match[ins] = 1;
        else match[ins]++;
        
        return;
    }
    
    for(int i = j; i < orders.size(); i++){
        if(!check[i]){
            check[i] = 1;
            combination(n, count + 1, i+1, check, orders);
            check[i] = 0;
        }
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> compare;
    vector<int> check(10,0);
    int max = 0;
    string all = "";
    
    for(int i = 0 ; i < orders.size() ; i++){
        for(int j = 0 ; j < orders[i].size() ; j++){
            compare.push_back(orders[i][j]); 
        }
        sort(compare.begin(), compare.end());
        for(int j = 0 ; j < course.size() ; j++){
            if(orders[i].length() >= course[j]){
                combination(course[j], 0, 0, check, compare);
                check.clear();
                check.resize(10, 0);
            }
        }
        compare.clear();
    }
    
    for(int i = 0 ; i < course.size() ; i++){
        auto maxit = match.begin();
        max = 0;
        map<string, int> mCount;
        for(auto it = match.begin() ; it != match.end() ; it++){
            if(it->first.length() == course[i]){
                mCount[it->first] = it->second;
                if(max < it->second) max = it->second;
            }
        }
        if(max < 2) continue;
        
        for(auto it = mCount.begin() ; it != mCount.end() ; it++){
            if(it->first.length() == course[i]){
                if(max == it->second){
                    answer.push_back(it->first);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}
