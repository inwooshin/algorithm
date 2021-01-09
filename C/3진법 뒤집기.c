#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    int complex, on = 0;
    int array[17], arrayInput = 0;

    for (int i = 17; i >= 0; i--) {
        complex = n / pow(3, i);
        n = n - pow(3, i) * complex;
        if (complex != 0) on = 1;
        if (on == 1) {
            array[arrayInput] = complex;
            arrayInput++;
        }
    }

    for (int i = 0; i < arrayInput; i++)
        answer += array[i] * pow(3, i);

    return answer;
}