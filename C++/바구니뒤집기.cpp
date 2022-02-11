#include <iostream> 

using namespace std; 

int main () { 
    int N, M; 

    cin >> N >> M; 

    int *basket = new int[N + 1]; 

    for (int i = 1; i <= N; i++) { 
        basket[i] = i; 
    } 

    for (int i = 0; i < M; i++) { 
        int A, B, tmp; 
        cin >> A >> B; 
        tmp = basket[A]; 
        basket[A] = basket[B]; 
        basket[B] = tmp; 
    } 

    for (int i = 1; i <= N; i++) { 
        cout << basket[i] << ' '; 
    } 

    return 0; 
}
