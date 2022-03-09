#include <iostream>

using namespace std;

int getSmall(int a, int b){
    if(a < b){
        return a;
    }
    else return b;
}

int getBigger(int a, int b){
    if(a < b){
        return b;
    }
    else return a;
}

int main (void){
    int arr[3];
    
    cin >> arr[0] >> arr[1] >> arr[2];
    
    int smallest = getSmall(getSmall(arr[0], arr[1]), getSmall(arr[1], arr[2]));
    
    if(smallest == arr[0]) cout << smallest << " " << getSmall(arr[1], arr[2]) << " "
                                << getBigger(arr[1], arr[2]);
    if(smallest == arr[1]) cout << smallest << " " << getSmall(arr[0], arr[2]) << " "
                                << getBigger(arr[0], arr[2]);
    if(smallest == arr[2]) cout << smallest << " " << getSmall(arr[0], arr[1]) << " "
                                << getBigger(arr[0], arr[1]);
    
}