#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
	//유니크 함수는 시작과 끝에서 중복값을 제거하고 쓰레기값의 첫주소를 반환한다.
	//algorithm 헤더파일에 포함되어 있는 함수이다.

    return arr;
}

vector<int> mySolution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    //int len = arr.size(); 이렇게 해주고 for 문에 len 로 넣어주는게 더 오래걸린다. 
    
    for(int i = 0 ; i < arr.size()-1 ; i++)
        if(arr[i] != arr[i+1]) answer.push_back(arr[i+1]);

    return answer;
}
