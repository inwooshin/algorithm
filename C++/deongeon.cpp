#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int k_tmp = k, max = 0;
        for(int i = 0 ; i < dungeons.size() ; i++){
            if(k_tmp >= dungeons[i][0]){
                k_tmp -= dungeons[i][1];
                max++;
            }
        }
        if(max >= answer) answer = max;
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}