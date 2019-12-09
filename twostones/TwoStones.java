public class TwoStones {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        if(n % 2 == 1) {
            io.println("Alice");
        } else {
            io.println("Bob");
        }
        io.flush();
    }
}