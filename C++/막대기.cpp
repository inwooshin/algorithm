#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	//지민 - 64cm 막대기
	//Xcm 인 막대

	//64 32 16 8 4 2 1
	int X = 0;

	cin >> X;

	int arr[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int tmp = 0, count = 0;

	for (int i = 0; i < 7; i++) {
		if (X == tmp + arr[i]) {
			cout << ++count;
			break;
		}
		if (X > (tmp + arr[i])) {
			tmp += arr[i];
			count++;
		}
	}

	return 0;
}