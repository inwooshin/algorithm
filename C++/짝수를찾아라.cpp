
#include <iostream>

using namespace std;

int main()
{
    int arr[7] = {0,}, N = 0;
    
    cin >> N;
    
    for(int j = 0 ; j < N ; j++){
        
        int all = 0, min = 101, tmp = 0;
        
        for(int i = 0 ; i < 7 ; i++){
            cin >> tmp;
            
            if(tmp % 2 == 1) continue;
            
            all += tmp;
            if(tmp < min) min = tmp;
        }
        
        cout << all << " " << min << endl;
    }

    return 0;
}
