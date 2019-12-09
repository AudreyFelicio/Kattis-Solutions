public class AnotherCandies {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int t = io.getInt();
        for(int i = 0; i<t; i++) {
            int n = io.getInt();
            long counter = 0;
            for(int j = 0; j<n; j++) {
                long a = io.getLong();
                counter += (a%n);
            }
            if(counter % n == 0) {
                io.println("YES");
            } else {
                io.println("NO");
            }
        }
        io.flush();
    }
}