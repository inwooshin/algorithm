#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() < 2) return vector<int>(1,-1); 
    
	vector<int> answer = arr;
    int min =   2147483647;
    auto itr =answer.begin();
    for(int i = 0 ; i < answer.size() ; i++){
        if(min > answer[i]) {min =answer[i]; itr = answer.begin() + i;}
    }
    answer.erase(itr);
    
    return answer;
}

vector<int> MinSolution(vector<int> arr){
	auto itr = min_element(arr.begin(), arr.end());
	// min_element 함수는 주소값인 iterator를 리턴하는 함수이다!
	// *을 함수 앞에 붙여주면 주소에 있는 값을 불러온다.
	// 여기서 *를 사용하고  find 함수를 사용할 경우 
	// vector<int>::iterator itr = find (arr.begin(), arr.end(), min); 
	// 을 사용하면 된다! 
	// 그리고 find 함수에서 arr.begin()을 지워주면 int pos 값이 된다. 
    arr.erase(itr);
    
    return arr.empty()? vector<int>(1,-1): arr;
    //arr 가 비었으면 vector<int>(1,-1) 으로 새로운 벡터를 리턴해줄 수 있다. 
} 
