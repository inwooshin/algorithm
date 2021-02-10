#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> p) {
    vector<vector<long>> picture(m, vector<long>(n, 0));
    for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                picture[i][j]=(long)p[i][j];
            }
    }
    int max = 0, all, once = 0, near = 0, reCount = 0;
    vector<vector<int>> table(m, vector<int>(n, 0));
    vector<int> count(m*n, 0);
    vector<vector<long>> overlap(m * n, vector<long>(1, 0));
    vector<long> check(m * n, 0);
    map<long, long> reIndex;
    
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            near = 0;
            if(!once && picture[i][j]){table[i][j] = ++answer[0];   once = 1;  }
            if(picture[i][j] == 0) continue;
            if(i-1 >= 0 && picture[i][j] == picture[i-1][j]){
                near++;
                if(table[i][j] != 0 && table[i-1][j] != 0 && table[i-1][j] != table[i][j]){
                    if(table[i][j] > table[i-1][j]){
                        if(!check[table[i][j]]){
                            overlap[table[i-1][j]].push_back(table[i][j]);
                            check[table[i][j]] = 1;
                            reCount++;
                        }
                        table[i][j] = table[i-1][j];
                    }
                    else if(table[i][j] < table[i-1][j]){
                        if(!check[table[i-1][j]]){
                           overlap[table[i][j]].push_back(table[i-1][j]);
                           check[table[i-1][j]] = 1;
                            reCount++;
                        }
                        table[i-1][j] = table[i][j];
                    }
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
                if(table[i][j] != 0 && table[i][j-1] != 0 && table[i][j-1] != table[i][j]){
                    if(table[i][j] > table[i][j-1]){
                        if(!check[table[i][j]]){
                            overlap[table[i][j-1]].push_back(table[i][j]);
                            check[table[i][j]] = 1;
                            reCount++;
                        }
                        table[i][j] = table[i][j-1];
                    }
                    else if(table[i][j] < table[i][j-1]){
                        if(!check[table[i][j-1]]){
                           overlap[table[i][j]].push_back(table[i][j-1]);
                           check[table[i][j-1]] = 1;
                            reCount++;
                        }
                        table[i][j-1] = table[i][j];
                    }
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
                if(table[i][j] != 0 && table[i+1][j] != 0 && table[i+1][j] != table[i][j]){
                    if(table[i][j] > table[i+1][j]){
                        if(!check[table[i][j]]){
                            overlap[table[i+1][j]].push_back(table[i][j]);
                            check[table[i][j]] = 1;
                            reCount++;
                        }
                        table[i][j] = table[i+1][j];
                    }
                    else if(table[i][j] < table[i+1][j]){
                        if(!check[table[i+1][j]]){
                           overlap[table[i][j]].push_back(table[i+1][j]);
                           check[table[i+1][j]] = 1;
                            reCount++;
                        }
                        table[i+1][j] = table[i][j];
                    }
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
                if(table[i][j] != 0 && table[i][j+1] != 0 && table[i][j+1] != table[i][j]){
                    if(table[i][j] > table[i][j+1]){
                        if(!check[table[i][j]]){
                            overlap[table[i][j+1]].push_back(table[i][j]);
                            check[table[i][j]] = 1;
                            reCount++;
                        }
                        table[i][j] = table[i][j+1];
                    }
                    else if(table[i][j] < table[i][j+1]){
                        if(!check[table[i][j+1]]){
                           overlap[table[i][j]].push_back(table[i][j+1]);
                           check[table[i][j+1]] = 1;
                            reCount++;
                        }
                        table[i][j+1] = table[i][j];
                    }
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
            }
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            count[table[i][j]]++;
        }
    }
    
    for(int i = 1 ; count[i] != 0 ; i++){
        int nCount = 0;
        if(overlap[i].back()){
            for(int j = 1 ; j < overlap[i].size() ; j++){
                nCount += count[overlap[i][j]];
                //cout << "i : " << i << ", j : " << j << ", overlap : " << overlap[i][j] << endl;
            }
        }
        nCount += count[i];
        //cout << "Count[" << i << "] : " << count[i] << endl;
        if(max < nCount){max = nCount;}
    }
    
    answer[0] = answer[0] - reCount;
    answer[1] = max;
    
    return answer;
}
