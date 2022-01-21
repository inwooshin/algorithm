#include <string>
#include <iostream>

using namespace std;

int main(void) {

	int L = 0, P = 0, allP = 0;
	int input[5] = { 0, };
	long long answer = 0;

	cin >> L >> P;

	allP = L * P;

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
		cout << input[i] - allP << " ";
	}

	return 0;
}