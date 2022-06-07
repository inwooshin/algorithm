
#include <iostream>

using namespace std;

int main()
{
    int num, count = 0;
    
    while(cin >> num){
        count = 0;
        if(num == 0) break;
        
        while(num != 0){
            int now = num % 10;
            num /= 10;
            
            if(now == 1) count += 2;
            else if(now == 0) count += 4;
            else count += 3;
            
            count++;
        }
        
        cout << count + 1 << endl;
    }

    return 0;
}
