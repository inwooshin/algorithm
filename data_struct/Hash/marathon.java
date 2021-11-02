import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class Solution {
    public String solution(String[] participant, String[] completion) {
        //parti 가 참가자 comp 가 완주자 그래서 한명씩 빠져있음
        String answer = "";
        
        //동명이인이 있을 수 있음
        HashMap<String, Integer> testMap = new HashMap<String, Integer>();

        for(int i = 0 ; i <completion.length ; i++){
            if(!testMap.containsKey(completion[i])){
                testMap.put(completion[i], 1);
            }
            else{
                testMap.put(completion[i], testMap.get(completion[i]) + 1);
            }
        }
        
        for(int i = 0 ; i < participant.length ; i++){
            if(!testMap.containsKey(participant[i])){
                answer = participant[i];
                break;
            }
            else{
                Integer now = testMap.get(participant[i]);
                if(now == 0){
                    answer = participant[i];
                    break;
                }
                testMap.put(participant[i], now - 1);
            }
        }
        
        
        return answer;
    }
}