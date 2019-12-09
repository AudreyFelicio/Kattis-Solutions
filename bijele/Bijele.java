public class Bijele {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        for(int i = 0; i<6; i++) {
            int n = io.getInt();
            if(i == 0) {
                io.println(1-n);
            } else if (i == 1) {
                io.println(1-n);
            } else if (i == 2 || i == 3 || i == 4) {
                io.println(2-n);
            } else {
                io.println(8-n);
            }
        }
        io.flush();
    }
}