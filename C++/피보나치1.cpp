#include <iostream>

using namespace std;

int main (void){
    int count, a, array[41] = {0, 1, 1,};
   
   cin >> count;
   
   for(int i = 2 ; i <= 40 ; i++){
      array[i] = array[i - 2] + array[i - 1];
   }
    
    for(int i = 0 ; i < count ; i++){
        cin >> a;
        
        if(a == 0){
            cout << 1 << ' ' << 0 << endl;
        }
        else if(a == 1) cout << 0 << ' ' << 1 << endl;
        else{
           cout << array[a - 1] << ' ' << array[a] << endl;
        }
    }
    
   return 0;
}
