#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

//pair를 사용한것보다 70~90배 가량 빠름 
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<bool> check(N+1, 0);
    vector<float> fail(N+1, 0), failure(N+1, 0);
    int size = stages.size();
    
    for(int i = 0 ; i < stages.size() ; i++) fail[stages[i] - 1]++;
    
    for(int i = 0 ; i < N ; i++){
        if(i == 0){
            failure.insert(failure.begin() + i, fail[i] / size);
            continue;
        }
        else failure.insert(failure.begin() + i, fail[i] / (size - fail[i - 1]));
        size -= fail[i - 1];
    }
    double max = 0;
    int maxi = 0;
    for(int i = 0 ; i < N ; i++){
        for(int i = 0 ; i < N ; i++){
            if(max < failure[i] && !check[i]){ max = failure[i]; maxi = i; 
                                             }
        }
        
        if(max == 0){
            for(int j = 0 ; j < N ; j++){
                if(!check[j]) {answer.push_back(j+1); check[j] = 1;}
            }
            break;
        }
        answer.push_back(maxi+1);
        check[maxi] = 1;
        max = 0;
    }
    
    return answer;
}

//반대로 들어온다! a 에는 뒤의 값이 b에는 a의 값이 들어온다.
bool compare (pair<double, int> &a, pair<double, int> &b){	//pair 로 두개 이상의 인수를 가진 값을 선언할 수 있다! 
	//참조로 가져오는 것은 첫번째 객체나 두번째 객체의 값을 비교하기 위함이다. 
    if(a.first == b.first) return a.second < b.second; // 뒤의 값보다 앞의 값이 더크면 바꿔라! (오름차순)
    // float 값이 동일할 경우에 인덱스 값을 비교하고 우측 값이 크면 바꿔준다. (내림차순이어서 큰값이 앞!) 
    return a.first > b.first;
    // 앞의 값보다 뒤의 값이 더 크면 바꿔준다. (내림차순)
}

vector<int> OtherSolution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> count(N+1,0);
    vector<pair<double,int>> fail;
    //두개 이상의 인수가 덩어리로 여러개 있는 집합인 배열을 선언! 
    double size = stages.size();
    
    for(int i = 0 ; i < size; i++) count[stages[i] - 1]++;
    
    for(int i = 0 ; i < N ; i++){
        if(size != 0)
            fail.push_back(make_pair(count[i]/ size, i+1));
        else fail.push_back(make_pair(0, i+1));
        size -= count[i];
    }
    
    sort(fail.begin(), fail.end(), compare);
    
    for(auto it = fail.begin() ; it != fail.end() ; it++){
        answer.push_back(it->second);
        //iterator 는 포인터 형식이기 때문에 it->second 와 같이해준다.
		//compare 함수의 경우는 참조 형식을 쓴것으로 각 배열이 갖고있는 객체에 접근하는 것이기 때문에 a.first 를 사용해준다. 
    }
    
    return answer;
}
