class Solution { 
    public int solution(String word) { 
        int answer = 0, wordEndLength = 4, alphabetInterval = 4; 
        int[] setRound = {781, 156, 31, 6, 0}; 
        for(int i = 0 ; i < word.length(); i++){ 
            int charNum = (word.charAt(i) - 'A') / alphabetInterval; 
            if(charNum == 5) charNum -= 1; 
            if(i == wordEndLength){
                answer += charNum + 1; 
                break;
            } 
            answer += setRound[i] * charNum + 1; 
        } 
        
        return answer; 
    } 
}
