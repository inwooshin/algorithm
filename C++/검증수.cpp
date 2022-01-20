#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	int input[5] = { 0, };
	long long answer = 0;

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 5; i++) {
		answer += pow(input[i], 2);
	}

	cout << answer % 10;

	return 0;
}