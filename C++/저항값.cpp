#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(void) {

    //1~2번째 저항의 색은 숫자를 의미
    //3번째 저항의 색은 10의 곱을 의미한다.

    vector<string> ohm = { "black", 
                           "brown" ,
                           "red"   ,
                           "orange",
                           "yellow",
                           "green" ,
                           "blue"  ,
                           "violet",
                           "grey"  ,
                           "white"  };
    string line;

    long long addAll = 0;

    for (int i = 0; i < 3; i++) {
        getline(cin, line);
        vector<string>::iterator index = find(ohm.begin(), ohm.end(), line);

        if (i == 0) addAll += (index - ohm.begin()) * 10;
        else if (i == 1) addAll += (index - ohm.begin());
        else if (i == 2) addAll *= pow(10, (index - ohm.begin()));
    }

    cout << addAll;
    
    return 0;
}