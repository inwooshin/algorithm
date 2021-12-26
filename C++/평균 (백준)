#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	
	int count = 0, max = 0;
	float allAdd = 0;
	string line;
	stringstream ss;
	vector<float> allScore;
	
	cin >> count;
	
	getline(cin, line);
	if(line.empty()) getline(cin, line);
	ss.str(line);

	for(int i = 0 ; i < count ; i++){
		int nScore;
		ss >> nScore;
		
		allScore.push_back(nScore);
		if(max < nScore) max = nScore;
	}
	
	for(int i = 0 ; i < allScore.size() ; i++){
		allAdd += (allScore[i] / max) * 100;
	}
	
	cout << allAdd / count;
	
	// your code goes here
	return 0;
}
