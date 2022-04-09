#include <iostream>

using namespace std;

int main()
{
    int N, M, L;
    
    cin >> N >> M >> L;

    int* arr = new int[N];
    int idx = 1, count = 0;
    arr[idx] = 1;
    
    while(count < 1000000){
        if(arr[idx] < M){
            count++;
            if(arr[idx] % 2 == 0){
                idx = (idx + L) % N;
                arr[idx]++;
            }
            else{
                idx -= L;
                if(idx < 0) idx = N + idx;
                
                arr[idx]++;
            }
        }
        else{
            cout << count;
            break;
        } 
    }

    return 0;
}
