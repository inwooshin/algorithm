#include <string>
#include <iostream>

using namespace std;


int getMax(int a, int b, int c) {
	int max = 0;

	if (a > b) max = a;
	else max = b;

	if (b > c) max = b;
	else max = c;

	return max;
}

int main(void) {

	int input[5] = { 0, };
	long long min = 2147483647;
	int max = 0;

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				long long lcm = 1;

				max = getMax(input[i], input[j], input[k]);

				for (int m = 1; m < 10000; m++) {
					if ((max * m) % input[i] == 0 && 
						(max * m) % input[j]== 0 &&
						(max * m) % input[k] == 0) {

						lcm = (max * m);
						break;
					}
				}
				
				if (lcm != 1 && lcm < min) min = lcm;
			}
		}
	}
	
	cout << min;

	return 0;
}