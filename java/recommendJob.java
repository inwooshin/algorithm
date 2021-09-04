import java.util.HashMap;

class Solution {
    public String solution(String[] table, String[] languages, int[] preference) {
        String answer = "";

        HashMap<Integer, String> Job = new HashMap<>();
        int[] score = new int[5];
        int max = 0, maxI = 0;

        for(int i = 0 ; i < table.length ; i++){
            String a[] = table[i].split(" ");

            Job.put(i, a[0]);

            for(int k = 0 ; k < languages.length ; k++) {
                for (int j = 1; j < a.length; j++) {
                    if(a[j].equals(languages[k])){ score[i] += (6 - j) * preference[k];

                        break;}
                }
            }

            if(max < score[i]){max = score[i]; maxI = i;}
        }

        String firstDic = Job.get(maxI);

        for(int i = 0 ; i < score.length ; i++){
            if(maxI != i && max == score[i]){
                if(firstDic.compareTo(Job.get(i)) > 0) firstDic = Job.get(i);
            }
        }

        return firstDic;
    }
}

class Solution {
    public String solution(String[] table, String[] languages, int[] preference) {
        String answer = "";
        int score=-1;
        for(String str : table){
            String[] t = str.split(" ");
            String tname = t[0];
            int tscore = 0;
            for(int i=0;i<languages.length;i++){
                int idx = Arrays.asList(t).indexOf(languages[i]);
                if(idx>-1) tscore+=preference[i]*(6-idx);
            }
            if(score ==tscore && answer.compareTo(tname)>0) answer=tname;
            if(score<tscore){
                score =tscore;
                answer= tname;
            }
        }

        return answer;
    }
}