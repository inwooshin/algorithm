#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());

    long long start = times[0];
    long long end = (long long)times.back() * n;

    long long answer = 0;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long count = 0;

        for (int i = 0; i < times.size(); i++) {
            count += mid / times[i];
        }

        if (count < n) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return start;
}