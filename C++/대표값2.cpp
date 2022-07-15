#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr;
    int all = 0;
    
    for(int i = 0 ; i < 5 ; i++){
        int tmp;
        
        cin >> tmp;
        
        all += tmp;
        
        arr.push_back(tmp);
        
    }
    
    sort(arr.begin(), arr.end());
    
    cout << all / 5 << endl << arr[2]; 

    return 0;
}
