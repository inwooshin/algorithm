import java.io.*;

public class n_count {
    public static void main(String ar[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int st = Integer.parseInt(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i = st ; i >= 1 ; i--){
            String a = "" + i;
            bw.write(a + '\n');
        }

        bw.flush();
    }
}
