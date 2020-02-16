import java.util.*;
import java.io.*;

public class ShatteredCake {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long w = Long.parseLong(br.readLine());
        int n = Integer.parseInt(br.readLine());
        long area = 0;
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long wi = Long.parseLong(st.nextToken());
            long li = Long.parseLong(st.nextToken());
            area += wi * li;
        }
        System.out.println( area / w );
    }
}
