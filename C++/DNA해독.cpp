#include <iostream>

using namespace std;

int str_to_int(char in){
    if(in == 'A') return 0;
    else if(in == 'G') return 1;
    else if(in == 'C') return 2;
    
    return 3;
}

int main()
{
    int num;
    string arr;
    string table[] = {"ACAG", "CGTA", "ATCG", "GAGT"};
    
    cin >> num;
    cin >> arr;
    
    while(arr.size() > 1){
        char first =  arr.back();
        arr.pop_back();
        
        char second =  arr.back();
        arr.pop_back();
        
        int row = str_to_int(first);
        int col = str_to_int(second);
        
        arr.push_back(table[row][col]);
    }
    
    cout << arr;

    return 0;
}
