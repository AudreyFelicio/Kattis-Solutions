public class PieceOfCake2 {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int h = io.getInt();
        int v = io.getInt();
        int area1 = h*v;
        int area2 = h*(n-v);
        int area3 = v*(n-h);
        int area4 = (n-v)*(n-h);
        io.println(4*Math.max(area1,Math.max(area2,Math.max(area3,area4))));
        io.flush();
    }
}