import java.util.*;
import java.io.*;

public class JollyJumpers {
    public static void initialize(boolean[] arr, int n) {
        for(int i = 1; i < n; i++) {
            arr[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        boolean[] arr = new boolean[300000];
        while( (line = br.readLine()) != null ) {
            StringTokenizer st = new StringTokenizer(line);
            int n = Integer.parseInt(st.nextToken());
            initialize(arr, n);
            int current = Integer.parseInt(st.nextToken());
            for(int i = 1; i < n; i++) {
                int temp = Integer.parseInt(st.nextToken());
                arr[Math.abs(temp - current)] = true;
                current = temp;
            }
            boolean jolly = true;
            for(int i = 1; i < n; i++) {
                jolly = jolly && arr[i]; 
            }
            if(jolly) {
                System.out.println("Jolly");
            } else {
                System.out.println("Not jolly");
            }
        }
    }
}
