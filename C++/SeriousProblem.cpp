#include <iostream>

using namespace std;

int main(void){
    
    int N, chE = 0, num2 = 0;
    string msg;
    
    cin >> N >> msg;
    
    for(int i = 0 ;i < N ; i++){
        if(msg[i] == '2') num2++;
        else chE++;
    }
    
    if(chE == num2) cout << "yee";
    else if(chE > num2) cout << 'e';
    else cout << '2';
    
    return 0;
}
