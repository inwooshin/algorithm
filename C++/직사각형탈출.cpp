#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
    
    int nowX, nowY, toX, toY;
    int least = 0;

    cin >> nowX >> nowY >> toX >> toY;

    if (nowX <= nowY) least = nowX;
    else least = nowY;

    if (toX - nowX <= toY - nowY) {
        if (toX - nowX <= least) least = toX - nowX;
    }
    else if (toY - nowY <= least) least = toY - nowY;

    cout << least;
    
    return 0;
}