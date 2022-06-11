#include <iostream>

using namespace std;

int main()
{
    int arr[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int day, month, year;
    
    
    while(true){
        cin >> day >> month >> year;
        
        //cout << year << endl;
        if(year == 0) break;
        
        int all = 0;
        
        for(int i = 0 ; i < month ; i++){
            all += arr[i];
        }
        
        all += day;
        
        if(year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    if(month >= 3){
                        all += 1;
                    }
                }
            }
            else{
                if(month >= 3){
                        all += 1;
                }
            }
        }
        
        cout << all << endl;
    }

    return 0;
}
