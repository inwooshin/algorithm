import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        HashMap<String, Integer> testMap = new HashMap<String, Integer>();

        for(int i = 0 ; i < completion.length ; i++){
            if(testMap.containsKey(completion[i])){
                int getId = testMap.get(completion[i]);
                testMap.put(completion[i], ++getId);
            }
            else {
                testMap.put(completion[i], 1);
            }
        }

        for(int i = 0 ; i < participant.length ; i++){
            if(!testMap.containsKey(participant[i])){
                answer = participant[i];
                break;
            }
            else{
                int getId = testMap.get(participant[i]) - 1;
                if(getId < 0){
                    answer = participant[i];
                    break;
                }

                testMap.put(participant[i], getId);
            }
        }

        return answer;
    }
}