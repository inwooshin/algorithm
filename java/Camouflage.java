import java.util.HashMap;
import java.util.Map;

class Solution {

    public int solution(String[][] clothes) {
        int answer = 1;

        Map<String, Integer> map = new HashMap<>();

        for(int i = 0 ; i < clothes.length ; i++){
            if(!map.containsKey(clothes[i][1])) map.put(clothes[i][1], 2);
            else map.put(clothes[i][1], map.get(clothes[i][1]) + 1);
        }

        for(Integer i : map.values()){
            answer *= i;
        }

        return answer - 1;
    }
}