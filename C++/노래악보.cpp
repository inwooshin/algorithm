#include <iostream>

using namespace std;

int main()
{
    int N, Q, T, j = 0, count = 0;
    
    cin >> N >> Q;
    
    int* arr = new int[N * 100];
    
    for(int i = 1 ; i <= N ; i++){
        cin >> T;
        for(count = 0 ; count < T ; j++){
            arr[j] = i;
            count++;
        }
    }
    
    for(int i = 0 ; i < Q ; i++){
        cin >> T;
        cout << arr[T] << endl;
    }

    return 0;
}
