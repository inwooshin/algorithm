#include <iostream>

using namespace std;

int main(void) {

	int N = 0, M = 0, K = 0;

	cin >> N >> M >> K;

	cout << (int) (K / M) << " " << K % M;

	return 0;
}