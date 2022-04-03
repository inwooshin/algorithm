#include <iostream>

using namespace std;

int main()
{
    int arr[101][101] = {{0,},}, num = 0, answer = 0;
    int x = 0, y = 0;
    
    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        cin >> x >> y;
       
        for(int j = x; j < x + 10 ; j++){
            for(int k = y; k < y + 10 ; k++ ){
                arr[j][k]++;
            }
        }
    }
    
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            if(arr[i][j] > 0){
                answer++;
            }
        }
    }
    
    cout << answer;

    return 0;
}
