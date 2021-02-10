#include <vector>

using namespace std;

vector<vector<int>> check, picture;

int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
int dm, dn;

int DFS(int i, int j, int color){
    check[i][j] = 1;
    int max = 1;
    
    for(int k = 0 ; k < 4 ; k++){
        int dx = i + x[k];
        int dy = j + y[k];
        
        if(dx >= 0 && dx < dm && dy >=0 && dy < dn){
            if(!check[dx][dy] && color == picture[dx][dy])    max += DFS(dx,dy, color);
        }
    }
    
    return max;
}

vector<int> solution(int m, int n, vector<vector<int>> pic) {
    picture = pic;
    int number_of_area = 0;
    check.assign(m,vector<int>(n, 0));
    
    int max = 0, now;
    dm = m;
    dn = n;
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!check[i][j] && picture[i][j] != 0){
                now = DFS(i,j,picture[i][j]);
                number_of_area++;
            }
            if(max < now) max = now;
        }
    }
    
    return vector<int>{number_of_area, max};
}
