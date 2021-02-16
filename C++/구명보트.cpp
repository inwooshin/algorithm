#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0, i = 0, count = 0;
    vector<bool>check(people.size(), 0);
    sort(people.begin(), people.end());
    
    for(int j = people.size() - 1 ; j >= 0 && i < people.size() ;j--){
        if(check[i] || check[j]) break;
        if(people[i] + people[j] <= limit){
            answer++;
            check[i] = 1, check[j] = 1;
            i++;
        }
        else{answer++; check[j] = 1;}
    }
    
    return answer;
}
