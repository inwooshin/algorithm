#include <iostream>

using namespace std;

int main()
{
    string name;
    int num;
    int arr[26] = {0, }, count = 0;
    
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> name;
        
        int alpha = (int)(name[0] - 'a');
        
        arr[alpha]++;
    }
    
    for(int i = 0 ; i < 26 ; i++){
        if(arr[i] >= 5){
            cout << (char)('a' + i);
            count = 1;
        }
    }
    
    if(count == 0) cout << "PREDAJA";

    return 0;
}
