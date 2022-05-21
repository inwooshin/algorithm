#include <iostream>

#include <cmath>

using namespace std;

int main()

{

    long long bP = 0, bGap = 0, P, Q, num;

    int on = 0;

    long long bSGap = 0;

    

    cin >> num;

    

    for(int i = 0 ; i < num ; i++){

        cin >> P;

        

        if(i == 0){

            bP = P;

            continue;

        }

        

        if(i == 2){

            if(bGap == P - bP) on =0;

            else on = 1;

        }

        

        if(i >= 2 && i < num - 1)

            continue;

        

        if(i == num - 1){

            if(on == 0)

                cout << P + bGap;

            else

                cout << P * bSGap;

        

        }

        

        bGap = P - bP;

        bSGap = P / bP;

        

        bP = P;

    }

    return 0;

}
