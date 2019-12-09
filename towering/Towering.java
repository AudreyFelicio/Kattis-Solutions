import java.util.*;
public class Towering {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int[] heights = new int[6];
        for(int i = 0; i<6; i++) {
            heights[i] = io.getInt();
        }
        int twr1 = io.getInt();
        int twr2 = io.getInt();
        int[] h1 = new int[3];
        int[] h2 = new int[3];
        Arrays.sort(heights);
        for(int i = 5; i>=0; i--) {
            for(int j = i-1; j>=0; j--) {
                for(int k = j-1; k>=0; k--) {
                    if(heights[k] + heights[j] + heights[i] == twr1) {
                        h1[0] = heights[i];
                        h1[1] = heights[j];
                        h1[2] = heights[k];
                    } else if (heights[k] + heights[j] + heights[i] == twr2) {
                        h2[0] = heights[i];
                        h2[1] = heights[j];
                        h2[2] = heights[k];
                    }
                }
            }
        }
        io.println(h1[0]);
        io.println(h1[1]);
        io.println(h1[2]);
        io.println(h2[0]);
        io.println(h2[1]);
        io.println(h2[2]);
        io.flush();
    }
}