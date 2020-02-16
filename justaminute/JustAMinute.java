import java.util.*;
import java.io.*;

public class JustAMinute {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double trainMinutes = 0;
        double realMinutes = 0;
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            realMinutes += 60 * Integer.parseInt(st.nextToken());
            trainMinutes += Integer.parseInt(st.nextToken());
        }
        double ans = trainMinutes/realMinutes;
        if(ans <= 1) {
            System.out.println("measurement error");
        } else {
            System.out.println(ans);
        }
    }
}
