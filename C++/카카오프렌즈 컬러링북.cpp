#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> count;
vector<vector<long>> overlap;
vector<long> check;
map<long, long> reIndex;
int once = 0, near = 0, reCount = 0, countAll = 0;

void setArea(int m, int n, int i, int j, vector<vector<int>> picture, vector<vector<int>>& table, vector<int>& answer){
    near = 0;
    if(!once && picture[i][j]){table[i][j] = ++answer[0];   once = 1;}
            if(picture[i][j] == 0) return;
            if(i-1 >= 0 && picture[i][j] == picture[i-1][j]){
                near++;
                if(table[i][j] != 0 && table[i-1][j] != 0 && table[i-1][j] != table[i][j]){
                    if(table[i][j] > table[i-1][j]){
                        table[i][j] = table[i-1][j];
                        setArea(m, n, i, j, picture, table, answer);
                    }
                    else if(table[i][j] < table[i-1][j]){
                        table[i-1][j] = table[i][j];
                        setArea(m, n,i-1, j, picture, table, answer);
                    }
                }
                if(table[i][j] == 0 && table[i-1][j] != 0) {
                    table[i][j] = table[i-1][j];
                                       }
                else if(table[i][j] == 0 && table[i-1][j] == 0){
                    table[i][j] = answer[0];
                }
            }
            if(j-1 >= 0 && picture[i][j] == picture[i][j-1]){
                near++;
                if(table[i][j] != 0 && table[i][j-1] != 0 && table[i][j-1] != table[i][j]){
                    if(table[i][j] > table[i][j-1]){
                        table[i][j] = table[i][j-1];
                        setArea(m, n,i, j, picture, table, answer);
                    }
                    else if(table[i][j] < table[i][j-1]){
                        table[i][j-1] = table[i][j];
                        setArea(m, n,i, j-1, picture, table, answer);
                    }
                }
                
                if(table[i][j] == 0 && table[i][j-1] != 0) table[i][j] = table[i][j-1];
                else if(table[i][j] == 0 && table[i][j-1] == 0){
                    table[i][j] = answer[0];
                }
            }
            if(i+1 < m && picture[i][j] == picture[i+1][j]){
                near++;
                if(table[i][j] != 0 && table[i+1][j] != 0 && table[i+1][j] != table[i][j]){
                    if(table[i][j] > table[i+1][j]){
                        table[i][j] = table[i+1][j];
                        setArea(m, n,i, j, picture, table, answer);
                    }
                    else if(table[i][j] < table[i+1][j]){
                        table[i+1][j] = table[i][j];
                        setArea(m, n,i+1, j, picture, table, answer);
                    }
                }
                
                if(table[i][j] == 0 && table[i+1][j] != 0) table[i][j] = table[i+1][j];
                else if(table[i][j] == 0 && table[i+1][j] == 0){
                    answer[0]++;
                    table[i][j] = answer[0];
                }
            }
            if(j+1 < n && picture[i][j] == picture[i][j + 1]){
                near++;
                if(table[i][j] != 0 && table[i][j+1] != 0 && table[i][j+1] != table[i][j]){
                    if(table[i][j] > table[i][j+1]){
                        table[i][j] = table[i][j+1];
                        setArea(m, n,i, j, picture, table, answer);
                    }
                    else if(table[i][j] < table[i][j+1]){
                        table[i][j+1] = table[i][j];
                        setArea(m, n,i, j+1, picture, table, answer);
                    }
                }
                
                if(table[i][j] == 0 && table[i][j+1] != 0) table[i][j] = table[i][j+1];
                else if(table[i][j] == 0){
                    answer[0]++;
                    table[i][j] = answer[0];
                }
            }
            if(near == 0){
                answer[0]++;
                table[i][j] = answer[0];
            }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int max = 0, all;
    vector<vector<int>> table(m, vector<int>(n, 0));
    count.assign(m*n, 0);
    overlap.assign(m * n, vector<long>(1, 0));
    check.assign(m * n, 0);
    
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            setArea(m,n,i, j, picture, table, answer);
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(table[i][j] != 0 && !check[table[i][j]]){
                countAll++; 
                check[table[i][j]] = 1;
            }
            count[table[i][j]]++;
            cout << table[i][j] << "    ";
        }
        cout << endl;
    }
    
    for(int i = 1 ; i < count.size() ; i++){
        int nCount = 0;
        if(count[i] == 0) continue;
        //cout << "Count[" << i << "] : " << count[i] << endl;
        if(max < count[i]){max = count[i];}
    }
    
    
    answer[0] = countAll;
    answer[1] = max;
    
    return answer;
}
