import java.util.*;
import java.io.*;

public class ThanosTheHero {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] planets = new int[n];
        boolean suicide = false;
        long ans = 0L;
        for(int i = 0; i < n; i++) {
            planets[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = n - 2; i >= 0; i--) {
            if(planets[i] >= planets[i+1]) {
                ans += planets[i] - planets[i+1] + 1;
                planets[i] = planets[i+1] - 1;
                if(planets[i] < 0) {
                    suicide = true;
                    break;
                }   
            }
        }
        if(suicide) {
            System.out.println(1);
        } else {
            System.out.println(ans);
        }
    }
}
