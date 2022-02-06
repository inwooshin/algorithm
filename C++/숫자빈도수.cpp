#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {

	int input, num, count = 0;
	cin >> input >> num;

	for (int i = 1; i <= input; i++) {
		int tmp = i;
		while (tmp) {
			if (tmp % 10 == num) count++;
			tmp /= 10;
		}
	}

	cout << count;

	return 0;
}