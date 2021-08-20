import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;

        Map<String, Integer> hash = new HashMap<>();

        for(int i = 0 ; i < phone_book.length ; i++)
            hash.put(phone_book[i], 0);

        for(int i = 0 ; i < phone_book.length ; i++){
            for(int j = 0 ; j < phone_book[i].length() ; j++){
                if(hash.containsKey(phone_book[i].substring(0,j))) return false;
            }
        }

        return true;
    }
}