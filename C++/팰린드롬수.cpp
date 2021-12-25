#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int answer = 0;
	string line = "";

	while (getline(cin, line)) {
		if (line == "0") break;
		int isPalindrome = 1, size = line.size();

		for (int i = 0; i < size; i++) {
			if (line[i] == line[size - 1 - i]);
			else isPalindrome = 0;
		}

		if (isPalindrome) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	cout << answer;

	return 0;
}