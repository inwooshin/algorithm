
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int number = 0;
    string before, now, max;
    
    while(cin >> number){
        if(number == 0) break;
        
        for(int i = 0 ; i < number ;i++){
            if(i == 0){ cin >> before; max = before; continue; }
            
            cin >> now;
            
            string tmpa = "", tmpb = "";
            
            for(int j = 0 ; j < max.size() ; j++){
                tmpa += toupper(max[j]);
            }
            for(int j = 0 ; j < now.size() ; j++){
                tmpb += toupper(now[j]);
            }
            
            if(tmpa > tmpb) max = now;
        }
        
        cout << max << endl;
    }

    return 0;
}
