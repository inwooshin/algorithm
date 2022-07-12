#include <iostream>

using namespace std;

int main()
{
    string universe = "CAMBRIDGE";
    string input;
    
    cin >> input;
    
    for(int i = 0 ; i < universe.size() ; i++){
        while(input.find(universe[i]) != -1){
            int npos = input.find(universe[i]);
            
            input.erase(npos, 1);
        }
    }
    
    cout << input;

    return 0;
}


