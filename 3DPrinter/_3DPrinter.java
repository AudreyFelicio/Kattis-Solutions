import java.util.*;
import java.io.*;

public class _3DPrinter {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int count = 1;
        int ans = 1;
        while(count < n) {
            count *= 2;
            ans++;
        }
        System.out.println(ans);
    }
}
