import java.math.BigInteger;
public class Different {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        while(io.hasMoreTokens()) {
            String a = io.getWord();
            String b = io.getWord();
            BigInteger one = new BigInteger(a);
            BigInteger two = new BigInteger(b);
            BigInteger result = one.subtract(two);
            io.println(result.abs());
        }
        io.flush();
    }
}