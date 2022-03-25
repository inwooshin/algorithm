#include <iostream>

using namespace std;

int main (void){
    
    int N, M;
    cin >> N >> M;
    
    int* box = new int[N];
    int* book = new int[M];
    int all = 0;
    
    for(int i = 0 ; i < N ; i++){
        cin >> box[i];
    }
    
    for(int i = 0 ; i < M ; i++){
        cin >> book[i];
    }
    
    int recentBox = 0;
    for(int i = 0 ; i < M ; i++){
    if(box[recentBox] - book[i] >= 0){
        box[recentBox] -= book[i];
    }
    else{
        recentBox++;
        i--;
    }
    }
    
    for(int i = 0 ; i < N ; i++){
        all += box[i];
    }
    
    cout << all;
    
return 0; 
}