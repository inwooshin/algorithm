#include <iostream>

using namespace std;

int getBigger(int a, int b){
    if(a > b){
        return a;
    }
    else return b;
}

int main()
{
    int arr[3], money = 0, N, max = 0;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[0] >> arr[1] >> arr[2];
        
        if(arr[0] == arr[1] && arr[1] == arr[2]){
            money = 10000 + (arr[0] * 1000);
        }
        else if(arr[0] == arr[1]){
            money = 1000 + arr[0] * 100;
        }
        else if(arr[1] == arr[2]){
            money = 1000 + arr[1] * 100;
        }
        else if(arr[0] == arr[2]){
            money = 1000 + arr[0] * 100;
        }
        else{
            money = getBigger(getBigger(arr[0], arr[1]), getBigger(arr[1], arr[2])) * 100;
        }
       
        if(max < money ) max = money;
    }
    
    cout << max;
    
    return 0;
}
