import java.util.Arrays;

class Solution {
    public int max_min(int def, int myScore, int score[][]){
        int max = 0, maxCount = 0;
        int min = 101;

        for(int i = 0 ; i < score.length;i++){
            if(def != i) {
                if(max < score[i][def])max = score[i][def];
            }
        }

        for(int i = 0 ; i < score.length; i++){
            if(def != i) {
                if(min > score[i][def]) min = score[i][def];
            }
        }

        if(max < myScore || min > myScore) return -1;

        return 1;
    }

    public String getGrade(float in){
        if(in >= 90) return "A";
        else if(in >= 80 && in <90) return "B";
        else if(in >= 70 && in < 80) return "C";
        else if(in >= 50 && in < 70) return "D";
        else return "F";
    }

    public String solution(int[][] scores) {
        String answer = "";

        for(int i = 0 ; i < scores.length ; i++){
            int check = max_min(i, scores[i][i], scores);
            int avg = 0, length = scores.length;

            for(int j = 0 ; j < scores.length ; j++){
                avg += scores[j][i];
            }

            if(check == -1 ){ avg -= scores[i][i];
                length = scores.length - 1;}

            answer += getGrade(avg / (float)length);
        }

        return answer;
    }
}