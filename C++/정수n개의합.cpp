#include <vector>

long long sum(std::vector<int> &a){
    long long all = 0;
    
    for(auto i = a.begin() ; i != a.end() ; i++){
        all += *i;
    }
    
    return all;
}
