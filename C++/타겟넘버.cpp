#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 모든 경우의 수를 비트 연산자를 사용해서 계산한 것...! 
int solution(vector<int> numbers, int target) {
    int answer = 0, all = 0, before = 0;
    int size = 1 << numbers.size();
    
    for(int i = 0 ; i < numbers.size() ; i++){
        before += numbers[i];
    }
    
    for(int i = 0 ; i < size ; i++){
        all = before;
        for(int j = 0 ; j < numbers.size(); j++){
            if(i & (1 << j)){
                all -= numbers[j] * 2;
            }
        }
        if(all == target) answer++;
    }
    
    return answer;
}

// 참고용 코드 DFS 를 사용해서 값을 도출한  것 
void dfs(vector<int>& numbers, int target, int& answer, int count, int all){
    if(count == numbers.size() - 1){
        if(all + numbers[count] == target) answer++;
        if(all - numbers[count] == target) answer++;
        
        return;
    }
    
    dfs(numbers, target, answer, count + 1, all + numbers[count]);
    dfs(numbers, target, answer, count + 1, all - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer, 0, 0);
    return answer;
}

// 비트 연산을 한 것! 
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {  
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}



