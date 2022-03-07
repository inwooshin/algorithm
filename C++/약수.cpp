#include <iostream>

using namespace std;

int main()
{
    int N, answer = 0;
    int max = 0, min = 1000001;
    
    cin >> N;
    
    int* arr = new int[N];
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
        
        if(max < arr[i]) max = arr[i];
        if(min > arr[i]) min = arr[i];
    }
    
    cout << max * min;

    return 0;
}
