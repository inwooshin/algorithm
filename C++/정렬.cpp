#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	string input;

	cin >> input;

	sort(input.rbegin(), input.rend());

	cout << input;

	return 0;
}