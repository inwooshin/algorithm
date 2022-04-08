#include <iostream>
#include <algorithm>

using namespace std;

int rev(string input){
    reverse(input.begin(), input.end());
    
    return stoi(input);
}

int main()
{
    string first, second;
    
    cin >> first >> second;
    
    cout << rev(to_string(rev(first) + rev(second)));

    return 0;
}
