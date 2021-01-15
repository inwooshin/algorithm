#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int solution(string s) {
    int answer = 0, count = 0;
    vector <int> array;
    
    for(int i = 1 ; i < s.size(); i++){
        string tmp = "";
        int n;
        if(isdigit(s[i-1])){
            if(i > 1 && isdigit(s[i-2])) n = (s[i-2] - '0') * 10 + s[i-1] - '0';
            else n = s[i-1] - '0';
        }
        
        if(s[i] == 'S'){ 
            array.push_back(n); 
            count++;}
        else if(s[i] == 'D'){ 
            array.push_back(pow(n,2));
            count++;}
        else if(s[i] == 'T'){ 
            array.push_back(pow(n, 3)); 
            count++;}
        else if(s[i] == '*'){
            if(i == 2) array[count - 1] += array[count - 1];
            else{
                array[count - 1] += array[count - 1];
                array[count - 2] += array[count - 2];
            }
        }
        else if(s[i] == '#'){
            array[count - 1] *= -1;
        }
    }
    
    for(int i = 0 ; i < count ; i++){
        answer += array[i];
    }
    return answer;
}

//스트링 스트림으로 문자열 컨트롤하기 공부 
// 이것을 사용해서 문자열을 컨트롤할 수 있다. 
void Practice(void) { 
 	int num;
 	char ch;
	stringstream stream1;

	string string1 = "25abss 55 asdbsd";	  
	stream1.str(string1);

	//스트링 스트림으로 하면 int 형으로 하면 2자리수 3자리수, 한 뭉텅어리로 나온다.
	stream1 >> num;
	cout << "num: " << num << endl;  // displays numbers, one per line
	
	//문자열을 get 하면 1개의 문자열씩만 들어온다.  
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	
	//unget 을 하면 get 하기 이전으로 돌아간다. 
	stream1.unget();
	stream1.unget(); 
	stream1 >> num;
	cout << "num: " << num << endl;

} 
