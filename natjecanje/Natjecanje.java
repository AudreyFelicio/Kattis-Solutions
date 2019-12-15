import java.util.*;
public class Natjecanje {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int s = io.getInt();
        int r = io.getInt();
        int[] damaged = new int[s];
        int[] reserve = new int[r];
        for(int i = 0; i<s; i++) {
            damaged[i] = io.getInt();
        }
        for(int i = 0; i<r; i++) {
            reserve[i] = io.getInt();
        }
        Arrays.sort(damaged);
        Arrays.sort(reserve);
        int ans = 0;
        int i = 0;
        int j = 0;
        int consecutivedmg = 0;
        int consecutiversv = 0;
        while(i < s && j < r) {
            if(damaged[i] == reserve[j]) {
                i += 1;
                j += 1;
                consecutivedmg += 1;
                consecutiversv += 1;
                if(consecutiversv < consecutivedmg) {
                    ans += 1;
                }
                consecutiversv = 0;
                consecutivedmg = 0;
            } else if (damaged[i] > reserve[j]) {
                if(damaged[i] == reserve[j] + 1) {
                    consecutiversv += 1;
                    j += 1;
                } else {
                    j += 1;
                    consecutiversv += 1;
                    if(consecutiversv < consecutivedmg) {
                        ans += 1;
                    }
                    consecutiversv = 0;
                    consecutivedmg = 0;
                }
            } else if (damaged[i] < reserve[j]) {
                if(damaged[i] + 1 == reserve[j]) {
                    consecutivedmg += 1;
                    i += 1;
                } else {
                    i += 1;
                    consecutivedmg += 1;
                    if(consecutiversv < consecutivedmg) {
                        ans += 1;
                    }
                    consecutiversv = 0;
                    consecutivedmg = 0;
                }
            }
        }
        if(i+1 == j && reserve[j-1] + 1 == damaged[i]) {
            io.println(ans);
        } else if(i < s) {
            io.println(ans+s-i);
        } else {
            io.println(ans);
        }
        io.flush();
    }
}