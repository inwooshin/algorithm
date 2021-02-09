#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int max = 0, all, once = 0, near = 0, reCount = 0;
    vector<vector<int>> table(m, vector<int>(n));
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
            if(j-1 >= 0 && picture[i][j] == picture[i][j-1]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != table[i][j]){
                    overlap[table[i][j]].push_back(table[i][j-1]);
                    reCount++;
                    continue;
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
            if(i+1 < m && picture[i][j] == picture[i+1][j]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != table[i][j]){
                    overlap[table[i][j]].push_back(table[i][j-1]);
                    reCount++;
                    continue;
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
            if(j+1 < n && picture[i][j] == picture[i][j + 1]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != table[i][j]){
                    overlap[table[i][j]].push_back(table[i][j-1]);
                    reCount++;
                    continue;
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
            cout << "i : " << i << ", j : " << j << ", count : " << count[table[i][j]] << ", table : " << table[i][j] << ", answer : " << answer[0] << endl;
        }
    }
    
    for(int i = 1 ; i < count.size() ; i++){
        
        if(max < count[i]) max = count[i];
    }
    answer[0] = answer[0] - reCount;
    answer[1] = max;
    
    return answer;
}

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
