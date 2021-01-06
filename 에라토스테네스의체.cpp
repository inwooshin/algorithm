#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool>isPrime(n + 1, true);

    for(int i = 2 ; i * i <= n ; i++){
        if(isPrime[i]){
            for(int j = i * i ; j <= n ; j += i){
                isPrime[j] = 0;
            }
        }
    }

    for(int i = 2 ; i < isPrime.size(); i++){
        if(isPrime[i] == true) answer++;
    }


    return answer;
}
