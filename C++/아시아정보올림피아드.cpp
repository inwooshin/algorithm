#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int>b){
    return a[2] > b[2];
}

int main(void) {

	int N;
	cin >> N;

	int country, num, score, count = 0;
	int check[100] = {0,};

	vector <vector <int>> scoreArr;
	
	for(int i = 0 ; i < N ; i++){
	    cin >> country >> num >> score;
	    //cout << country << " " << num << " " << score << endl;
	    vector <int> tmp;
	    tmp.push_back(country);
	    tmp.push_back(num);
	    tmp.push_back(score);
	    
	    scoreArr.push_back(tmp);
	}
	
	sort(scoreArr.begin(), scoreArr.end(), cmp);
	
	for(int i = 0 ; i < N ; i++){
	    if(++check[scoreArr[i][0]] < 3){
	        cout << scoreArr[i][0] << " " << scoreArr[i][1] << endl;
	        if(++count > 2) break;
	    }
	}
	
	return 0;
}