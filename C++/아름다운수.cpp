#include <iostream>

using namespace std;

int main()
{
    string bchar = "1234567890";
    string input;
    int num, count = 0;
    
    cin >> num;
    
    for(int j = 0 ; j < num ; j++){
        count = 0;
        
        cin >> input;
        
        for(int i = 0 ; i < bchar.size() ; i++){
            if(input.find(bchar[i]) != -1) count++;
        }
        
        cout << count << endl;
    }
    

    return 0;
}
