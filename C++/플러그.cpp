#include <iostream>

using namespace std;

int main()
{
    int num, all = 0;
    
    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        int tmp;
        cin >> tmp;
        
        all += tmp;
    }
    
    cout << all - (num - 1);

    return 0;
}
