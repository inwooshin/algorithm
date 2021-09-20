import java.util.*;


public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        for(int i = 0 ; i < arr.length ; i++){
            if(i == 0){ answer.add(arr[i]); continue;}
            
            if(answer.get(answer.size() - 1) != arr[i]) answer.add(arr[i]);
        }

        int toArray[] = answer.stream().mapToInt(i->i).toArray();
        
        return toArray;
    }
}
