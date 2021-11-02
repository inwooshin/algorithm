import java.util.HashSet;

class Solution {
    public boolean solution(String[] phoneBook) {
        boolean answer = false;

        HashSet<String> set = new HashSet<>();

        for(int i = 0 ; i < phoneBook.length ; i++){
            set.add(phoneBook[i]);
        }

        for(int i = 0 ; i < phoneBook.length ; i++){
            for(int j = 0 ; j < phoneBook[i].length() ; j++){
                if(set.contains(phoneBook[i].substring(0,j))) return false;
            }
        }

        return true;
    }
}