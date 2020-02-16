import java.util.*;
import java.io.*;

public class SumKindOfProblem {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int p = Integer.parseInt(br.readLine());
        for(int i = 0; i < p; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int s1 = ( n * (n+1))/2;
            int s2 = n * n;
            int s3 = n * (n+1);
            System.out.println(k + " " + s1 + " " + s2 + " " + s3);
        }
    }
}
