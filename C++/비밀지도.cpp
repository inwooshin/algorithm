#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> binary(vector<int> decimal, vector<int> comp, int n){
    vector<int> ans;
    vector<string> toString;
    string tmp;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            if(decimal[i] % 2 == 1) ans.push_back(1);
            else ans.push_back(0);
            decimal[i] /= 2;
        }
        
        for(int j = 0 ; j < n ; j++){
            if(comp[i] % 2 == 1) ans[j] |= 1;
            comp[i] /= 2;
        }
        
        for(int j = 0 ; j < n ; j++){
            if(ans[n - j - 1]) tmp += '#';
            else tmp += ' ';
        }
        toString.push_back(tmp);
        ans.clear();
        tmp.clear();
    }
    
    return toString;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    answer = binary(arr1, arr2, n);
    return answer;
}

vector<string> OtherSoulution(int n, vector<int> arr1, vector<int> arr2){
	vector<string> answer;
	
	for(int i = 0 ; i < n ; i++){
		arr1[i] = arr1[i]|arr2[i];
		string tmp = "";
		for(int j = 0 ; j < n ; j++){
			if(arr1[i] % 2 == 0) tmp = ' ' + tmp;
			// 이렇게 하면 문자열의 앞에 값을 입력할 수 있다! 
			else tmp = '#' + tmp;
			arr1[i] /= 2;
		}
		answer.push_back(tmp);
	}
    return answer;
}

int main (void){
	int a = 3, b =5;
	a = a | b;
	
	//이와 같이 인트를 OR 비트 연산을 하면, 자동으로 컴파일러가 011, 101 로 바꿔서 or 를 해주고
	//111로 변환한다음에 7의 값이 들어간다. 
	
	cout << a << endl;
	
	a = 3;
	b = 5;
	a = a& b;
	cout << a << endl;
	
	//이와 같이 인트를 AND 연산해도 일일이 이진으로 비교하고 저장된다. 
	return 0;
} 
