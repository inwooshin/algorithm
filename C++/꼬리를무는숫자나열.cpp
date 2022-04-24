#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, M;
    
    cin >> N >> M;
    
    N -= 1;
    M -= 1;
    
    int row = abs((int)(M / 4) - (int)(N / 4));
    int col = abs((int)(M % 4) - (int)(N % 4));
    
    cout << row + col;

    return 0;
}