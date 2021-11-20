import java.util.HashMap;
import java.util.HashMap;
import java.util.Iterator;


class Solution {

    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i = 0 ; i < clothes.length ; i++){
            if(!map.containsKey(clothes[i][1])) map.put(clothes[i][1], 2);
            else map.put(clothes[i][1], map.get(clothes[i][1]) + 1);
        }
        
        for(String i : map.keySet()){
            answer *= map.get(i);
        }
        
        return answer - 1;
    }
}