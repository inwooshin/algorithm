#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	//우리가 사용하는 연도와 다른 방식을 이용한다.
	//수 3개를 이용해서 연도
	//지구, 태양, 그리고 달

	//지구 - E <= 15, 태양 - S <= 28, 달 - M <= 19

	int E = 15, S = 28, M = 19, count = 0;
	cin >> E >> S >> M;

	for (int i = 0; i < 7980; i++) {
		count++;

		if ((count - E) % 15 == 0 && (count - S) % 28 == 0 && (count - M) % 19 == 0) {
			cout << count;
			return 0;
		}
	}

	return 0;
}