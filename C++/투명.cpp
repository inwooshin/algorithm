#include <iostream>

using namespace std;

int main()
{
    int N, M, px, py, qx, qy, answer = 0;
    
    cin >> N >> M;
    
    int check[101][101] = {{0,},};

    for(int i = 0 ; i < N ; i++){
        cin >> px >> py >> qx >> qy;
        for(int j = py ; j <= qy ; j++){
            for(int k = px ; k <= qx ; k++){
                check[j][k] += 1;
            }
        }
    }
    
    for(int i = 0 ; i <= 100 ; i++){
        for(int j = 0 ; j <= 100 ; j++){
            if(check[i][j] > M) answer++;
        }
    }
    
    cout << answer;
    return 0;
}
