#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length(), length = 1, count = 0, before = 1001, lenCount = 1;
    
    if(s.length() == 1) return 1;
    
    while(length != s.length()){
        string com = "";
        string zip = "";
        for(int i = 0 ; i < s.length() ; i += length){
            string all = s.substr(i, s.length());
            if(i+length > s.length() - 1){
                if(length == 1 && !com.compare(s.substr(i, length))) count++;
                if(count > 0){
                    cout << "up" << endl;
                    zip += to_string(count + 1) + com;
                                  count = 0;}
                else{ cout << "down" << endl;
                    zip += s.substr(i, s.length());}
                
                if(com.find(s[i]) != 0) zip += s.substr(i, s.length());
                
                break;
            }
            if(all.find(s.substr(i, length)) == 0){
                if(!com.compare(s.substr(i, length))) count++;
                else if(count == 0) zip += com;
                else if(count > 0){
                    zip += to_string(count + 1) + com;
                    count = 0;
                }
                com = s.substr(i, length);
            }
            else zip += s.substr(i, length);
        }
        if(before > zip.length()) before = zip.length();
        count = 0;
        length++;
        
        cout << "zip : " << zip << endl;
    }
    
    return before;
}
