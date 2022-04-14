#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234, count = 0, tmp = 0;
    vector<int> all(1);
    
    for(int i = 0 ; i < board.size(); i++){
        count = 0, tmp = 0;
        for(int j = 0 ; j < board[0].size() ; j++){
            if(board[i][j] == 1){count++; tmp++;}
            else if(count != 0) {
                //마지막일때도 해야됨=
                for(int k = i+1 ; k < i + count - 1 ; k++){
                    for(int l = j ; l < j + count ; l++){
                        //if(k >= board.size() - 1 || l >= board.size() - 1) break;
                        if(board[k][l] == 1) tmp++;
                    }
                }
                if(tmp == count * count) all.push_back(tmp);
                tmp = 0;
            }
            else if(count != 0 && j == board[0].size() - 1){
                for(int k = i+1 ; k < i + count - 1 ; k++){
                    for(int l = j ; l < j + count ; l++){
                        //if(k >= board.size() - 1 || l >= board[0].size() - 1) break;
                        if(board[k][l] == 1) tmp++;
                    }
                }
                if(tmp == count * count) all.push_back(tmp);
                tmp = 0;
            }
            cout << tmp << endl;
        }
    }

    int max = *max_element(all.begin(), all.end());
    
    return max;
}