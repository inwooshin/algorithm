#include <string>
#include <iostream>

using namespace std;

int main(void) {

	string input;
	int alpha[27] = { 0, }, max = 0, maxCount = 0, maxIndex = 0;

	cin >> input;

	for (auto i : input) {
		if (i >= 'a' && i <= 'z') {
			alpha[i - 'a']++;
			if (max < alpha[i - 'a']) {
				max = alpha[i - 'a'];
			}
		}
		else {
			alpha[i - 'A']++;
			if (max < alpha[i - 'A']) {
				max = alpha[i - 'A'];
			}
		}
	}

	for (int i = 0; i < 27; i++) {
		if (max == alpha[i]) {
			maxCount++;
			if (maxCount > 1) {
				cout << '?';
				return 0;
			}
			maxIndex = i;
		}
	}

	cout << (char)('A' + maxIndex);

	return 0;
}