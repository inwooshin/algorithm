#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int all = brown + yellow, i;
    
    for(i = 1 ; true ; i++){
        if(!(yellow % i) && (i +2) * (yellow / i + 2) == all)   break;
    }
    
    // 이 식으로 answer.push_back() 이렇게 일일이 하는 것이 아니라 다른 것으로 바꿔줄 수 있다. 
    return vector<int>{yellow / i + 2, i+2};
}
