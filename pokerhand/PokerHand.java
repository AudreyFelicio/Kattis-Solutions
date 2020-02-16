import java.util.*;
import java.io.*;

public class PokerHand {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        char[] rank = new char[5];
        for(int i = 0; i < 5; i++) {
            rank[i] = st.nextToken().charAt(0);
        }
        Arrays.sort(rank);
        int ans = 1;
        int temp = 1;
        for(int i = 0; i < 4; i++) {
            if(rank[i] == rank[i+1]) {
                temp++;
            } else {
                ans = Math.max(ans, temp);
                temp = 1;
            }
        }
        ans = Math.max(ans, temp);
        System.out.println(ans);
    }
}
