import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Vector;
import java.util.Arrays;

class Solution {
    
    public int[] solution(String[] genres, int[] plays) {
        int genresCount = 0, count = 0;
        
        Map<String, Integer> max = new HashMap();
        HashMap<String, HashMap<Integer, Integer>> list = new HashMap<String, HashMap<Integer, Integer>>();
        
        //String 배열은 멤버 변수!인 length 사용
        for(int i = 0 ; i < genres.length ; i++){
            //System.out.println(genres[i]);
            
            if(max.containsKey(genres[i])){
                max.put(genres[i], max.get(genres[i]) + plays[i]);
            }
            else{
                max.put(genres[i], plays[i]);
            }
            
            if(!list.containsKey(genres[i])){
                HashMap<Integer, Integer> inList = new HashMap<>();
                inList.put(i, plays[i]);
                list.put(genres[i], inList);
                genresCount++;
            }
            else {
                HashMap<Integer, Integer> inList = list.get(genres[i]);
                inList.put(i, plays[i]);
                list.put(genres[i], inList);
            }
        }
        
        Vector<Integer> vector = new Vector<>();
        //정렬하기
        // Map.Entry 리스트
        List<Entry<String, Integer>> entryList = new ArrayList<Entry<String, Integer>>(max.entrySet());

        // Comparator를 사용하여 정렬
        Collections.sort(entryList, new Comparator<Entry<String, Integer>>() {
            // 값 비교
            public int compare(Entry<String, Integer> obj1, Entry<String, Integer> obj2) {
                // 내림차순 정렬
                return obj2.getValue().compareTo(obj1.getValue());
            }
        });
        
        for(Entry<String, Integer> entry : entryList){
            Map<Integer, Integer> inListtmp = list.get(entry.getKey());
            
            List<Entry<Integer, Integer>> inListtmpentryList = new ArrayList<Entry<Integer, Integer>>(inListtmp.entrySet());

            // Comparator를 사용하여 정렬
            Collections.sort(inListtmpentryList, new Comparator<Entry<Integer, Integer>>() {
                // 값 비교
                public int compare(Entry<Integer, Integer> obj1, Entry<Integer, Integer> obj2) {
                    // 내림차순 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            
            int tmpCount = 0;
            for(Entry<Integer, Integer> tmp : inListtmpentryList){
                vector.add(tmp.getKey());
                tmpCount++;
                if(tmpCount % 2 == 0) break;
            }
        }
        
        int[] answer = new int[vector.size()];
        int answerCount = 0;
        
        for(int i : vector){
            answer[answerCount++] = i;
        }
        
        return answer;
    }
}