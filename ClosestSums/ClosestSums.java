import java.util.*;
import java.io.*;

public class ClosestSums {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int cases = 1;
        while( (line = br.readLine()) != null ) {
            int n = Integer.parseInt(line);
            int[] nums = new int[n];
            for(int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(br.readLine());
            }
            int m = Integer.parseInt(br.readLine());
            System.out.println("Case " + cases + ":");
            for(int i = 0; i < m; i++) {
                int target = Integer.parseInt(br.readLine());
                int closest = nums[0] + nums[1];
                for(int j = 0; j < n; j++) {
                    for(int k = j+1; k < n; k++) {
                        int sum = nums[j] + nums[k];
                        if(Math.abs(sum - target) < Math.abs(closest - target)) {
                            closest = sum;
                        }
                    }
                }
                System.out.println("Closest sum to " + target + " is " + closest + ".");
            }
            cases++;
        }
    }
}
