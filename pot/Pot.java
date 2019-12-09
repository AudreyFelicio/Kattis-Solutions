public class Pot {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int counter = 0;
        for(int i = 0; i<n; i++) {
            int k = io.getInt();
            counter += Math.pow((k-(k%10))/10, k%10);
        }
        io.println(counter);
        io.flush();
    }
}