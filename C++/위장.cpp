#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(int i = 0 ; i < clothes.size() ; i++){
        //m 은 해당 인덱스에 있는 값이 초기화 되어있다?
		// 그래서 += 으로 도 입력이 가능하다. 
		m[clothes[i][1]] += 1;
    }
    
    //face 2개 head 2개 일경우 face 2 + 아무것도 안쓰는 경우의 수(1) = 3
	//head 에서 2 + 아무것도 안쓰는 경우의 수(1) = 3
	//총 경우의 수는 face(3) * head(3) = 9 개이다. 여기서 예외처리로 전부다 벗지는 않음으로 최종값에
	//-1 을 해준다. 
    for(auto it = m.begin() ; it != m.end() ; it++){
        answer *= it->second + 1;
    }
    
    return answer - 1;
}
