#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string,vector<int>> own;
    vector<string>infoOwn(4);
    int beg = 0, end = 0, all, score;
    
    for(int i = 0 ; i < info.size() ; i++){
        beg = 0, end = 0;
        for(int j = 0 ; j < 5 ; j++){
            if(j == 4){
                score = stoi(info[i].substr(end + 1, info[i].length() - end));
                break;
            }
            end = info[i].find(" ", beg);
            all = end - beg;
            infoOwn[j] = info[i].substr(beg,all);
            beg = beg + all + 1;
        }
        
        for(int k = 0 ; k < 16 ; k++){
            string tmp = "";
            for(int j = 0 ; j < 4 ; j++){
                if(k & (1 << j)) tmp += infoOwn[j];
                else tmp += "-";
            }
            own[tmp].push_back(score);
        }
    }
    
    for(auto& it : own){
        sort(it.second.begin(), it.second.end());
    }
    
    for(int i = 0 ; i < query.size() ; i++){
        beg = 0, end = 0;
        string compareTmp = "";
        for(int j = 0 ; j < 5 ; j++){
            if(j == 4){
                score = stoi(query[i].substr(end + 1, query[i].length() - end));
                break;
            }
            end = query[i].find(" ", beg);
            all = end - beg;
            compareTmp += query[i].substr(beg,all);
            beg = beg + all + 5;
        }
        
        answer.push_back(own[compareTmp].end() - lower_bound(own[compareTmp].begin(), own[compareTmp].end(), score));
    }
    
    return answer;
}
