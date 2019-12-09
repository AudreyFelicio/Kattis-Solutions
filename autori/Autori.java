import java.util.*;

public class Autori {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        String a = io.getWord();
        String b = "";
        for(int i = 0; i<a.length(); i++) {
            if(i == 0)  {
                b = b + a.charAt(i);
            } else if (a.charAt(i) == '-') {
                b = b + a.charAt(i+1);
            }
        }
        io.println(b);
        io.flush();
    }
}