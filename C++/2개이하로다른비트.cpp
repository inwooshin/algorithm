#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto i : numbers){
        long long xor_cmp = 0;
        
        if(i % 2 == 0){
            answer.push_back(i+1);
            continue;
        }
        
        int pos;
        long long one = 1;
        for(pos = 0 ; pos < 64 ; pos++){
            if(!(i & (one << pos))){ 
                break;
            }
        }
        
        i += (one << (pos -1));
        answer.push_back(i);
    }

    
    return answer;
}