#include <iostream>

using namespace std;

int main()
{
    int input, all = 10;
    
    while(cin >> input){
        
        if(input == 0) break;
        
        all = 10;
        
        while(all / 10 != 0){
            all = 0;
        
            while(input != 0){
                all += input % 10;
                input /= 10;
            }
            
            input = all;
        }
        
        cout << all << endl;
    }

    return 0;
}
