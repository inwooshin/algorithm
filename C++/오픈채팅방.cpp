#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> split(string input, char deli){
    vector<string> answer;
    stringstream ss(input);
    string tmp;
    
    while(getline(ss, tmp, deli)){
        answer.push_back(tmp);
    }
    
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> allName;
    string enter_leave = "";

    for(auto i : record){
        vector<string> tok = split(i, ' ');
        string tmp = "";
        
        if(tok[0] == "Enter"){
            if(tok.size() == 3){
                allName[tok[1]] = tok[2];
                answer.push_back(tok[1]);
                enter_leave += "E";
            }
            else {
                enter_leave += "E";
            }
        }
        else if(tok[0] == "Leave"){
            answer.push_back(tok[1]);
            enter_leave += "L";
        }
        else if(tok[0] == "Change"){
            allName[tok[1]] = tok[2];
        }
    }
    
    for(int i = 0 ; i < answer.size(); i++){
        if(enter_leave[i] == 'E'){
            answer[i] = allName.find(answer[i])->second + "님이 들어왔습니다.";
        }
        else {
            answer[i] = allName.find(answer[i])->second + "님이 나갔습니다.";
        }
    }
    
    return answer;
}