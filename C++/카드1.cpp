#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    int N;
    
    cin >> N;
    
    for(int i = 1; i <= N ; i++){
        q.push(i);
    }
    
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    
    return 0;
}
