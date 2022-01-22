#include <string>
#include <iostream>

using namespace std;

int main(void) {

	int albumNum, ave = 0;

	cin >> albumNum >> ave;

	cout << albumNum * (ave - 1) + 1;

	return 0;
}