#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int count = 0;
    
    cin >> n >> k;
    
    int* arr = new int[n + 1];
    
    for(int i = 2 ; i <= n ; i++){
        if(arr[i] != 0) continue;
        
        //에라토스테네스의 체를 사용
        //각각 최대 소수가 어느 것인지 배열에 저장
        for(int j = i ; j <= n ; j+= i){
            if(arr[j] < i) arr[j] = i;
        }
    }
    
    for(int i = 1 ; i <=n ; i++){
        if(arr[i] <= k) count++;
    }

    cout << count;

    return 0;
}
