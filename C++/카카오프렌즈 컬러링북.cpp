#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > check;

int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
int dm, dn;

//vector 로 매개변수를 보낼 때 참조를 하지 않으면 메모리를 새롭게 만든다.
//원래의 vector 배열에 지장을 주지않는 새로운 배열을 만들어서 연산하기 때문이다.
//이렇게 참조를 하지 않으면 많은 메모리 접근으로 인해 프로그램이 느려진다. 
int DFS(int i, int j,  vector<vector<int> > picture){
    check[i][j] = 1;
    int max = 1;
    
    for(int k = 0 ; k < 4 ; k++){
        int dx = i + x[k];
        int dy = j + y[k];
        
        if(dx >= 0 && dx < dm && dy >=0 && dy < dn){
            if(!check[dx][dy] && picture[i][j] == picture[dx][dy])    max += DFS(dx,dy, picture);
        }
    }
    
    return max;
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    check.assign(m,vector<int>(n, 0));
    
    int max = 0, now;
    dm = m;
    dn = n;
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!check[i][j] && picture[i][j] != 0){
                now = DFS(i,j,picture);
                number_of_area++;
            }
            if(max < now) max = now;
        }
    }
    
    for(int i = 0 ; i < m ; i++){
    	for(int j = 0 ; j < n ; j++){
    		cout << picture[i][j] << "	";
		}
		cout << endl;
	}
    
    return vector<int>{number_of_area, max};
}

int main (){
	vector<int> a;
	a = solution(13, 16, {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0}, {0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}});

	cout << endl << a[0] << " : " << a[1] << endl;
}
