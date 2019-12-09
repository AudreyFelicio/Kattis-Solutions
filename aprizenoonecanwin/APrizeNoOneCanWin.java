import java.util.*;
public class APrizeNoOneCanWin {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int x = io.getInt();
        int[] price = new int[n];
        for(int i = 0; i<n; i++) {
            price[i] = io.getInt();
        }
        Arrays.sort(price);
        if(n == 1) {
            io.println(1);
        } else {
            int bool = 0;
            for(int i = 0; i<n-1; i++) {
                if(price[i] + price[i+1] > x) {
                    bool = 1;
                    io.println(i+1);
                    break;
                }
            }
            if(bool == 0) {
                io.println(n);
            }
        }
        io.flush();
    }
}