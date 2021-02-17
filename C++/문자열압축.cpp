#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(string s) {
    int answer = s.length(), length = 1, count = 0, before = 1001;
    
    if(s.length() == 1) return 1;
    
    while(length != s.length()){
        string com = "";
        string zip = "";
        for(int i = 0 ; i < s.length() ; i += length){
            string all = s.substr(i, s.length());
            if(i+length >= s.length()){
                if(length == s.length() - i && !com.compare(s.substr(i, length))){
                    zip += to_string(count + 2) + com;
                }
                else if(count > 0){
                    zip += to_string(count + 1) + com + s.substr(i, s.length());}
                else zip += com + s.substr(i, s.length());
                break;
            }
            if(!com.compare(s.substr(i, length))){count++;}
            else if(count > 0){
                zip += to_string(count + 1) + com;
                count = 0;
            }
            else if(i != 0 && count == 0){zip += com;}
            com = s.substr(i, length);
        }
        if(before > zip.length()) before = zip.length();
        count = 0;
        length++;
    }
    
    return before;
}


int solution(string s) {
    int answer = s.length(), length = 1, count = 0, before = 1001;
    
    if(s.length() == 1) return 1;
    
    while(length != s.length()){
        string com = "";
        string zip = "";
        for(int i = 0 ; i < s.length() ; i += length){
            string all = s.substr(i, s.length());
            //찾고자하는 패턴의 길이가 총 문자열의 길이를 넘어가거나 같을 경우
            if(i+length >= s.length()){
                //length가 나머지 찾지 않은 문자열의 길이와 같다면 문자열의 패턴을 비교한다.
                if(length == s.length() - i && !com.compare(s.substr(i, length))){
                    //여기서 +2 는 이미 있었던 count 에서 한번더 compare 해서 패턴을 발견해서 원래의 +1에서 한번더 추가했다.
                    zip += to_string(count + 2) + com;
                }
                //만약 찾지 못한채 이전에 패턴이 반복되었던 것이 있으면 반복된 패턴의 횟수와 문자를 넣어주고, 나머지 문자를 넣어준다.
                else if(count > 0){
                    zip += to_string(count + 1) + com + s.substr(i, s.length());}
                //아예 이전에 패턴이 반복도 안되고 나머지도 반복되지 않았다면 이전의 패턴과 나머지 문자열을 넣어준다.
                else zip += com + s.substr(i, s.length());
                //마지막이어서 break 한다.
                break;
            }
                //찾고자 하는 문자열이 이전의 패턴과 일치한다면 중복 횟수를 증가시켜준다.
            if(!com.compare(s.substr(i, length))){count++;}
            //아니라면 패턴이 변화한 것이다. 여기서 이전의 패턴이 반복되었다면 반복되었던 숫자와 문자열을 넣어준다.
            else if(count > 0){
                zip += to_string(count + 1) + com;
                count = 0;
            }
            //문자열이 찾고자 하는 패턴과 같지 않고 count 도 없을 경우에 이전의 문자를 zip에 넣어준다.
            else if(i != 0 && count == 0){zip += com;}
            com = s.substr(i, length);
        }
        if(before > zip.length()) before = zip.length();
        count = 0;
        length++;
    }
    
    return before;
}

//substr 함수는 i 부터 length 인덱스 사이의 문자열을 리턴한다.

