#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {

    //1. N 과 F 가 주어진다.
    //2. N 의 가장 뒤 두자리를 적절히 바꿔서 N을 F로 나누어 떨어지게 만든다.
    //   - 여기서 가능한한 최소한으로 만들고 싶다고 한다!
    
    long long N, F, addAll = 0;
    string str;

    cin >> N >> F;

    for (int i = 0; i < 100; i++) {
        addAll = (N / 100) * 100 + i;
        if (addAll % F == 0) break;
    }
    
    str = to_string(addAll);
    cout << str.substr(str.size() - 2, 2);

    return 0;
}