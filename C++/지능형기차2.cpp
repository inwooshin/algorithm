#include <iostream>

using namespace std;

int main(void){
    int out, in, max = 0,all = 0;
    
    while(cin >> out >> in){
        all += in;
        all -= out;
        if(max < all) max = all;
    }
    cout << max;
}
