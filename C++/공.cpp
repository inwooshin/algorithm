#include <iostream>

using namespace std;

int main()
{
    int N, arr[4] = {0, 1, 0, 0}, x, y, tmp;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> x >> y;
        
        tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }
    
    for(int i = 1 ; i < 4 ; i++){
        if(arr[i] == 1){
            cout << i;
            break;
        }
    }

    return 0;
}
