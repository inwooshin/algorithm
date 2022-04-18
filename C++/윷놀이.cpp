
#include <iostream>

using namespace std;

int main()
{
    int arr[4] = {0,};
    
    //배와 등이 나오는 숫자를 세어서 도개걸윷모를 결정
    
    for(int j = 0 ; j < 3 ; j++){
        int count = 0;
        for(int i = 0 ; i < 4 ; i++){
            cin >> arr[i];
            
            if(arr[i] == 1) count++;
        }
        
        if(count == 3){ 
            //도
            cout << 'A' << endl;
            continue;
        }
        if(count == 2){
            //개
            cout << 'B' << endl;
            continue;
        }
        if(count == 1){
            //걸
            cout << 'C' << endl;
            continue;
        }
        if(count == 0){
            //윷
            cout << 'D' << endl;
            continue;
        }
        if(count == 4){
            //모
            cout << 'E' << endl;
            continue;
        }
    }
    
    return 0;
}
