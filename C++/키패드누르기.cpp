#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;
double distance (int* a, int b){
    double dis = ceil(sqrt(pow(2 - a[0], 2) + pow((b+ 1) / 3 - a[1], 2)));
    
    return dis;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left[2] = {1,4}, right[2] = {1,4};
    for(int i = 0 ; i < numbers.size() ; i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){answer += 'L'; left[0] = 1; left[1] = (numbers[i] + 2) / 3;  continue;}
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {answer += 'R'; right[0] = 1; right[1] = numbers[i] / 3; continue;}
        
        if(numbers[i] == 0) numbers[i] = 11;
        double disL = distance(left, numbers[i]), disR = distance(right, numbers[i]);
        if(disL < disR) {
            answer += 'L'; left[0] = 2; left[1] = (numbers[i] + 1)/ 3;
        }
        else if(disL > disR){answer += 'R'; right[0] = 2; right[1] = (numbers[i] + 1)/ 3;}
        else if(hand == "right") {answer += 'R'; right[0] = 2; right[1] = (numbers[i] + 1)/ 3;}
        else {answer += 'L'; left[0] = 2; left[1] = (numbers[i] + 1)/ 3;}
    }
    return answer;
}
