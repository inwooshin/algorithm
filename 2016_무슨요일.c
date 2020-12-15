#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i, day = 0;

    for (i = 0; i < a - 1; i++)
        day += month[i];
    day += b;
    i = (day + 4) % 7;

    return answer[i];
}