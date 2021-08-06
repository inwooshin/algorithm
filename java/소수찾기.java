import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int count = 1000;
    static int[] all = new int[1001];

    public static void era(){
        for(int i = 2 ; i < 1001 ; i++){
            all[i] = 1;
        }

        for(int i = 2 ; i <= count ; i++){
            if(all[i] == 0) continue;
            for(int j = i + i ; j <= count ; j += i){
                all[j] = 0;
            }
        }
    }

    public static void main(String ar[]) throws IOException {
        int many = 0;

        era();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        StringTokenizer stInt = new StringTokenizer(br.readLine());

        for(int j = 1 ; j <= N ; j++) {
            int a = Integer.parseInt(stInt.nextToken());

            if(all[a] != 0){
                many++;
            }
        }

        bw.write(many + "");

        bw.flush();
    }
}
