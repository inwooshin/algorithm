#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool* isPrime;

void che(int n) {
    
    isPrime = (bool *)malloc(n+1);
    
    for(int i = 0 ; i < n+1 ; i++) isPrime[i] = true;
    isPrime[0] = false; isPrime[1] = false;
    for(int i = 2 ; i * i <= n ; i++){
        if(isPrime[i]){
            for(int j = i * i ; j <= n ; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

int solution(string numbers) {
    vector<int> all;
    string max = "";
    int answer = 0;
    
    for(int i = 0 ; i < numbers.length() ; i++){
        all.push_back(numbers[i] - '0');
    }
    
    sort(all.begin(), all.end());
    
    for(int i = all.size() - 1 ; i >= 0 ; i--){
        max += to_string(all[i]);
    }
    
    che(atoi(max.c_str()));
    
    do{
        for(int i = 0 ; i <= all.size(); i++){
            int tmp = 0;
            for(int j = 0 ; j < i ; j++){
                tmp = tmp * 10 + all[j];
                if(isPrime[tmp]){
                    answer++;
                    isPrime[tmp] = false;
                }
            }
        }
    } while(next_permutation(all.begin(), all.end())); 
    
    return answer;
}
