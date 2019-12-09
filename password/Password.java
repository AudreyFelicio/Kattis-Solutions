import java.util.*;
public class Password {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        double[] probs = new double[n];
        for(int i = 0; i<n; i++) {
            String a = io.getWord();
            probs[i] = io.getDouble();
        }
        Arrays.sort(probs);
        double counter = 0;
        for(int i = n-1; i>=0; i--) {
            counter += (n-i)*probs[i];
        }
        io.println(counter);
        io.flush();
    }
}