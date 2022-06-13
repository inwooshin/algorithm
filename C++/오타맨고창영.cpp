#include <iostream>

using namespace std;

int main()
{
    string input;
    int num;
    
    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        int point;
        cin >> point >> input;
        input.erase(point - 1, 1);
        
        cout << input << endl;
    }

    return 0;
}
