#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int answer = 0;
	string line = "a";

	for(int j = 0 ; !line.empty() ; j++){
		getline(cin, line);
		//cout << "cout : " << line << endl;

		for (int i = 0; i < line.length() ; i++) {
			if (j % 2 == 0 && i % 2 == 0 && line[i] == 'F') answer++;
			else if (j % 2 == 1 && i % 2 == 1 && line[i] == 'F') answer++;
		}
	}

	cout << answer;

	return 0;
}