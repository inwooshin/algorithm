#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> arr = {"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};
    
    string input;
    
    int N;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> input;
        
        int count[8] = {0,0,0,0,0,0,0,0};
        for(int j = 0 ; j < 38 ; j++){
            auto it = find(arr.begin(), arr.end(), input.substr(j, 3));
            
            if(it != arr.end()){
                count[it - arr.begin()]++;
            };
        }
        
        for(int j = 0 ; j < 8 ; j++){
            cout << count[j] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
