import java.util.*;
public class SymmetricOrder {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean stillInput = true;
        int k = 0;
        while (stillInput) {
            k = k+1;
            int n = input.nextInt();
            input.nextLine(); //consume newline left-over
            if(n == 0) {
                stillInput = false;
            } else {
                System.out.println("SET " + k);
                String[] names = new String[n];
                String[] ans = new String[n];
                for(int i = 0; i<n; i++) {
                    names[i] = input.nextLine();
                }
                int forward = 0;
                int backward = n-1;
                for(int i = 0; i<n ; i++) {
                    if(i % 2 == 0) {
                        ans[forward] = names[i];
                        forward += 1;
                    } else {
                        ans[backward] = names[i];
                        backward -= 1;
                    }
                }
                for(int i = 0; i<n; i++) {
                    System.out.println(ans[i]);
                }
            }
        }
    }
}