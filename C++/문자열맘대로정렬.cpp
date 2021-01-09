#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stn;

bool compare(string a, string b){
    if(a[stn] < b[stn]) return true;
    else if(a[stn] > b[stn]) return false;

    return b > a;
}

vector<string> solution(vector<string> strings, int n) {
    stn = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}
