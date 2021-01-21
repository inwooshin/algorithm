#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int i;
    
    sort(citations.begin(), citations.end());
    
    for(i = 0 ; i < citations.size() ; i++){
        if(citations[i] >= citations.size() - i) break;
    }
    
    return citations.size() - i;
}
