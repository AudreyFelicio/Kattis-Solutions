import java.util.*;
public class PlantingTrees {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int[] trees = new int[n];
        for(int i = 0; i<n; i++) {
            trees[i] = io.getInt();
        }
        Arrays.sort(trees);
        int temp = trees[n-1];
        int counter = 1;
        for(int i = n-2; i>=0; i--) {
            if(temp - trees[i] <= 1) {
                temp = trees[i];
                counter += 1;
            } else {
                temp = temp-1;
                counter += 1;
            }
        }
        io.println(counter+temp+1);
        io.flush();
    }
}