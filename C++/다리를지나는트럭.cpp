#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1; // 1초부터 값이 들어가기 때문에 증가를 시켜준것. 
	int all = 0, tmp;
    vector<int> count;
    stack <int> s, pass;
    queue <int> q;
    
    for(int i = 0 ; i < truck_weights.size(); i++){
        s.push(truck_weights[i]);
    }
    
    while(pass.size() != truck_weights.size()){
        if(!s.empty() && all + s.top() <= weight){
            tmp = s.top();
            s.pop();
            q.push(tmp);
            all += tmp;
            count.push_back(0);
        }
        for(int j = 0 ; j < count.size() ; j++){
            count[j]++;
            if(count[j] == bridge_length){
                tmp = q.front();
                q.pop();
                pass.push(tmp);
                all -= tmp;
            }
        }
        answer++;
    }
        
    
    return answer;
}

int otherSolution (int bridge_length, int weight, vector<int> truck_weights) {
	//length 만큼 더해주고 현재 시간을 더해준 것을 pair로 넣어주면 끝나는 시간이 나오게 된다.
	//그래서 현재 시간을 증가시켜주면서 front().second 의 값을 비교해보면 그것이 다리를 지났는지
	//알 수 있다!
	int answer = 0, i = 0, on = 0, time = 1;
	queue <pair<int, int>> q;
	
	while(1){
		//이미 다리에 올라가 있는 것과 넣을 것의 무게의 합이 다리가 견딜 수 있는 것보다 작거나 같으면,
		//push 해준다.
		if(weight >= truck_weights[i] + on){
			q.push(make_pair(truck_weights[i], time + bridge_length));
			on += truck_weights[i];
			i++; 
		}
		
		//마지막 트럭을 push 했을 때에 최종 도달 시간이 q의 두번째 인수에 들어와있기 때문에 answer 에
		//넣어주고 break 시킨다. 
		if(i >= truck_weights.size()){
			answer = q.back().second;
			break;
		}
		//시간을 1초씩 증가시켜주고 증가시켜준 값이 큐의 제일 앞에 있는 값의 두번째 값인 즉 다리를 다
		//건널 시간이 되면 다리에서 올라가있는 무게에서 빼주고 pop 해준다. 
		else {
			time++;
			if(time == q.front().second){
				on -= q.front().first;
				q.pop();
			}
		}
		
	}
	
	return answer;
}
