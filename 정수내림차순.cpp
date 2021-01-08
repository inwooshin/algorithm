#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(char a, char b){
    return a > b;
}

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), compare);
    long long answer = stol(s);
    
    return answer;
}
