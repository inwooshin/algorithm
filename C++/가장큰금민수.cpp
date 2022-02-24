#include <iostream>

using namespace std;

int main()
{
    //N마리의 새
    
    int N, answer = 0;
    
    cin >> N;
    
    for(int i = N ; i >= 4 ; i--){
        int tmp = i;
        int count = 0, check = 0;
        
        while(tmp != 0){
            count++;
            
            if(tmp % 10 == 4 || tmp % 10 == 7){
                check++;
                tmp /= 10;
            }
            else break;
        }
        
        if(count == check){
            answer = i;
            break;
        }
    }
    
    cout << answer;
    
    return 0;
}
