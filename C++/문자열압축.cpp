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
            if(i+length >= s.length() - 1){
                if(length <= s.length() - i && !com.compare(s.substr(i, length))) count++;
                if(count > 0){
                    zip += to_string(count + 1) + com;
                                  count = 0;}
                else if(count == 0) zip += com + s.substr(i, s.length());
                
                break;
            }
            if(all.find(s.substr(i, length)) == 0){
                if(!com.compare(s.substr(i, length))){count++;}
                else if(count > 0){
                    zip += to_string(count + 1) + com;
                    count = 0;
                }
                else if(i != 0 && count == 0){zip += s.substr(i, length);}

                com = s.substr(i, length);
            }
            else{zip += s.substr(i, length);}
            
        }
        cout << "length : " << length << ", zip : " << zip << endl;
        if(zip.empty()){
            count = 0;
            length++;
            continue;}
        if(before > zip.length()) before = zip.length();
        count = 0;
        length++;
        
    }
    
    return before;
}
