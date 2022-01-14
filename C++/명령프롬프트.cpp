#include <string>
#include <iostream>

using namespace std;

int main(void) {
	
	int count = 0;

	cin >> count;
	
	string* str = new string[count];
	string answer = "";

	for (int i = 0; i < count; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < str[0].length() ; i++) {
		int j = 1;
		char bef = str[0][i];

		for (; j < count; j++) {
			if (bef != str[j][i]) break;
		}

		if (j != count) answer += "?";
		else answer += str[0][i];
	}

	cout << answer;

	return 0;
}