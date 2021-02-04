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
