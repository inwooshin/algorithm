#include <iostream>
#include <vector>

using namespace std;

int han(int a){
    int tmp = 1, all = 99;
    int first, second, third, fourth, side1, side2;
    
    if(a < 100) return a;
    
    for(int i = 100 ; i <= a ; i++){
        tmp = i;
        first = tmp % 10;
        tmp /= 10;
        second = tmp % 10;
        tmp /= 10;
        third = tmp % 10;
        tmp /= 10;
        
        side1 = second - first;
        side2 = third - second;
        
        if(i == 1000){
            break;
        }
        else{
            if(side1 == side2) all++;
        }
    }
    
    return all;
}

int main (void){
    int a;
    
    cin >> a;
    
    cout << han(a);
}
