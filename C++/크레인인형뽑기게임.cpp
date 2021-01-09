#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, pickUp = 0;
    int movesLen = moves.size(), boardLen = board.size();
    vector<int> repeat;
    
    for(int i = 0 ; i < movesLen ; i++){
        for(int j = 0 ; j < boardLen ; j++){
            if(board[j][moves[i] - 1] != 0){
                repeat.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                pickUp = 1;
                break;
            }
        }
        int reSize = repeat.size();
        if(pickUp && reSize > 1){
            if(repeat[reSize - 2] == repeat[reSize - 1]){
                vector<int>::iterator iter = repeat.end();
                repeat.erase(iter - 2, iter);
                answer += 2;
            }
        }
        pickUp = 0;
    }
    
    return answer;
}
