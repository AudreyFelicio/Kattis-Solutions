import java.util.*;
import java.io.*;

public class GreedilyIncreasing {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] permutation = new int[n];
        for(int i = 0; i < n; i++) {
            permutation[i] = Integer.parseInt(st.nextToken());
        }
        ArrayList<Integer> sequence = new ArrayList<Integer>();
        int current = permutation[0];
        sequence.add(current);
        for(int i = 1; i < n; i++) {
            if(permutation[i] > current) {
                current = permutation[i];
                sequence.add(current);
            }
        }
        System.out.println(sequence.size());
        for(int i = 0; i < sequence.size(); i++) {
            if(i == sequence.size() - 1) {
                System.out.print(sequence.get(i));
            } else {
                System.out.print(sequence.get(i) + " ");
            }
        }
    }
}
