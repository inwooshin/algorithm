#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0, before = 0, count = 0;
    vector<bool> check(numbers.size(), 0);
    for(int i = 0 ; i < numbers.size(); i++) before += numbers[i];
    int all = before;
    
    do{
        for(int i = 0 ; i < numbers.size(); i++){
            if(all < target) break;
            else if(all == target){answer++;
                                  continue;}
            all -= numbers[i] * 2;
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}

// 참고용 코드 DFS 를 사용해서 값을 도출한  것 
void dfs(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0){
    if (count == numbers.size() - 1) {
        if (target == sum + numbers[count])        answer++;
        if (target == sum - numbers[count])        answer++;
        return;
    }
    dfs(numbers, answer, target, count + 1, sum + numbers[count]);
    dfs(numbers, answer, target, count + 1, sum - numbers[count]);
}
 
int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, answer, target);
    return answer;
}
