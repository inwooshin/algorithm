#include <iostream>

using namespace std;

int main()
{
    int T, n;
    
    cin >> T;
    
    for(int j = 0 ; j < T ; j++){ 
        cin >> n;
        
        int all = 0;
        for(int k = 1 ; k <= n ; k++){
            all += k * (0.5 * (k + 1) * (k + 2));
        }
        
        cout << all << endl;
    }
    

    return 0;
}
