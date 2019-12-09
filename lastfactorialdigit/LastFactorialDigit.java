public class LastFactorialDigit {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        for(int i = 0; i<n; i++) {
            int k = io.getInt();
            if(k == 0 || k == 1) {
                io.println(1);
            } else if (k == 2) {
                io.println(2);
            } else if (k == 3) {
                io.println(6);
            } else if (k == 4) {
                io.println(4);
            } else {
                io.println(0);
            }
        }
        io.flush();
    }
}