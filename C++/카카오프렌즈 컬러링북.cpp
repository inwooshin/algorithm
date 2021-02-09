#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int max = 0, all, once = 0, near = 0, reCount = 0;
    vector<vector<int>> table(m, vector<int>(n, 0));
    vector<int> count(m*n);
    vector<vector<int>> overlap(m * n, vector<int>(1));
    vector<int> check(m * n);
    
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            near = 0;
            if(!once && picture[i][j]){table[i][j] = ++answer[0];   once = 1;   }
            if(picture[i][j] == 0) continue;
            if(i-1 >= 0 && picture[i][j] == picture[i-1][j]){near++;
                if(table[i][j] != 0 && table[i-1][j] != 0 && table[i-1][j] != table[i][j] && !check[table[i-1][j]]){
                    check[table[i-1][j]] = 1;
                    overlap[table[i][j]].push_back(table[i-1][j]);
                    reCount++;
                    count[table[i][j]]++;
                    continue;
                }
                if(table[i][j] == 0 && table[i-1][j] != 0) {
                    table[i][j] = table[i-1][j];
                                       }
                else if(table[i][j] == 0 && table[i-1][j] == 0){
                    answer[0]++;
                    table[i][j] = answer[0];
                    table[i][j+1] = answer[0];
                }
            }
            if(j-1 >= 0 && picture[i][j] == picture[i][j-1]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != 0 && table[i][j-1] != table[i][j]&& !check[table[i][j-1]]){
                    check[table[i][j-1]] = 1;
                    overlap[table[i][j]].push_back(table[i][j-1]);
                    reCount++;
                    count[table[i][j]]++;
                    continue;
                }
                
                if(table[i][j] == 0 && table[i][j-1] != 0) table[i][j] = table[i][j-1];
                else if(table[i][j] == 0 && table[i][j-1] == 0){
                    answer[0]++;
                    table[i][j] = answer[0];
                    table[i][j+1] = answer[0];
                }
            }
            if(i+1 < m && picture[i][j] == picture[i+1][j]){
                near++;
                if(table[i][j] != 0 && table[i+1][j] != 0 && table[i+1][j] != table[i][j]&& !check[table[i+1][j]]){
                    check[table[i+1][j]] = 1;
                    overlap[table[i][j]].push_back(table[i+1][j]);
                    reCount++;
                    count[table[i][j]]++;
                    continue;
                }
                
                if(table[i][j] == 0 && table[i+1][j] != 0) table[i][j] = table[i+1][j];
                else if(table[i][j] == 0 && table[i+1][j] == 0){
                    answer[0]++;
                    table[i][j] = answer[0];
                    table[i][j+1] = answer[0];
                }
            }
            if(j+1 < n && picture[i][j] == picture[i][j + 1]){
                near++;
                if(table[i][j] != 0 && table[i][j+1] != 0 && table[i][j+1] != table[i][j]&& !check[table[i][j+1]]){
                    check[table[i][j+1]] = 1;
                    overlap[table[i][j]].push_back(table[i][j+1]);
                    reCount++;
                    count[table[i][j]]++;
                    continue;
                }
                
                if(table[i][j] == 0 && table[i][j+1] != 0) table[i][j] = table[i][j+1];
                else if(table[i][j] == 0){
                    answer[0]++;
                    table[i][j] = answer[0];
                    table[i][j+1] = answer[0];
                }
            }
            if(near == 0){
                answer[0]++;
                table[i][j] = answer[0];
                count[answer[0]]++;}
            else {  count[table[i][j]]++;}
        }
    }
    
    for(int i = 1 ; count[i] != 0 ; i++){
        int nCount = 0;
        if(overlap[i].back()){
            for(int j = 0 ; j < overlap[i].size() ; j++){
                nCount += count[overlap[i][j]];
                //cout << "i : " << i << ", j : " << j << ", overlap : " << overlap[i][j] << endl;
            }
        }
        nCount += count[i];
        if(max < nCount){max = nCount;}
    }
    
    /*
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << table[i][j] << "    ";
        }
        cout << endl;
    }
    */
    
    answer[0] = answer[0] - reCount;
    answer[1] = max;
    
    return answer;
}

/*
0    0    0      0    0    0     0     1     1     0     0     0     0     0     0    0    
0    0    0      0    0    0     2     2     1     1     0     0     0     0     0    0    
0    0    0      0    3    3     2     2     1     1     1     1     0     0     0    0    
0    0    0      4    4    3     2     2     1     1     1     1     1     0     0    0    
0    0    5      5    4    3     2     2     1     1     1     1     1     1     0    0    
0    6    6      5    4    7     2     2     1     1     8     1     1     1     1    0    
0    6    6      5    9    10    11    2     1     12    13    14    1     1     1    0    
0    6    6      5    5    10    10    2     1     1     13    13    1     1     1    0    
0    6   15     15   15    10    10    2     1     1     13    16    16    16    1    0    
0    6    6      6    6    10    17    2     1     18    13    13    13    13    1    0    
0    0    6      6    6    10    10    19    19    20    20    13    13    13    0    0    
0    0    0      6    6    10    10    10    10    20    20    13    13    0     0    0    
0    0    0      0    6    10    10    10    10    20    20    13    0     0     0    0 
*/

//반복을 허용하지 않은 상태
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int max = 0, all, once = 0, near = 0;
    vector<vector<int>> table(m, vector<int>(n, 0));
    vector<int> count(m*n);
    vector<vector<int>> overlap(m, vector<int>(n));
    
    vector<int> answer(2);
    answer[0] = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            near = 0;
            if(!once && picture[i][j]){table[i][j] = 1;   once = 1;   }
            if(picture[i][j] == 0) continue;
            if(i-1 >= 0 && picture[i][j] == picture[i-1][j]){
                near++;
                if(table[i][j] == 0 && table[i-1][j] == 0){
                    answer[0]++;
                }
                if(table[i-1][j] != 0) {table[i][j] = table[i-1][j];
                                       }
                else{
                    table[i][j] = answer[0];
                    table[i-1][j] = answer[0];
                }
                count[table[i][j]]++;
            }
            else if(j-1 >= 0 && picture[i][j] == picture[i][j-1]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != table[i][j]){
                    overlap[table[i][j]].push_back(table[i][j-1]);
                }
                if(table[i][j] == 0 && table[i][j-1] == 0){
                    answer[0]++;
                }
                if(table[i][j-1] != 0) table[i][j] = table[i][j-1];
                else{
                    table[i][j] = answer[0];
                    table[i][j-1] = answer[0];
                }
                count[table[i][j]]++;}
            else if(i+1 < m && picture[i][j] == picture[i+1][j]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != table[i][j]){
                    overlap[table[i][j]].push_back(table[i][j-1]);
                }
                if(table[i][j] == 0 && table[i+1][j] == 0){
                    answer[0]++;
                }
                if(table[i+1][j] != 0) table[i][j] = table[i+1][j];
                else{
                    table[i][j] = answer[0];
                    table[i+1][j] = answer[0];
                }
                count[table[i][j]]++;
            }
            else if(j+1 < n && picture[i][j] == picture[i][j + 1]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != table[i][j]){
                    overlap[table[i][j]].push_back(table[i][j-1]);
                }
                if(table[i][j] == 0 && table[i][j+1] == 0){
                    answer[0]++;
                }
                if(table[i][j+1] != 0) table[i][j] = table[i][j+1];
                else{
                    table[i][j] = answer[0];
                    table[i][j+1] = answer[0];
                }
                count[table[i][j]]++;
            }
            if(near == 0){
                answer[0]++;
                count[answer[0]]++;}
            //cout << "i : " << i << ", j : " << j << ", count : " << count[table[i][j]] << ", table : " << table[i][j] << ", answer : " << answer[0] << endl;
        }
    }
    
    for(int i = 1 ; i < count.size() ; i++){
        /*
        if(overlap[i][0] != 0){
            for(int j = 0 ; j < overlap[i].size() ; j++){
                max += count[overlap[i][j]];
            }
        }
        */
        if(max < count[i]) max = count[i];
    }
    answer[1] = max;
    
    return answer;
}
