public class Sibice {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int w = io.getInt();
        int h = io.getInt();
        double d = Math.sqrt(Math.pow(w,2) + Math.pow(h,2));
        for(int i = 0; i<n; i++) {
            int k = io.getInt();
            if(k > d) {
                io.println("NE");
            } else {
                io.println("DA");
            }
        }
        io.flush();
    }
}