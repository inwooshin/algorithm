#include <iostream>

using namespace std;

int main (void){
    int M, N, all, min = 10001;

    cin >> M >> N;

    for(int i = M ; i <= N ; i++){
        for(int j = 1 ; j * j <= i ; j++){
            if( i == j * j){
                all += i;
                
                if(min > i) min = i;
                break;
            }
        }
    }

    if(all != 0) cout << all << endl << min;
    else cout << -1;

    return 0;
}
