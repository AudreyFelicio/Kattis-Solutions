import java.util.*;
import java.lang.Math;

public class Planina {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int result = (int) Math.pow(2,n) + 1;
        io.println(result*result);
        io.flush();
    }
}