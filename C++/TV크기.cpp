#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int D, H, W;
    
    cin >> D >> H >> W;
    
    double all = D / (sqrt((H * H) + (W * W)));
    
    cout << (int)(H * all) << " " << (int)(W * all);
    
    return 0;
}
