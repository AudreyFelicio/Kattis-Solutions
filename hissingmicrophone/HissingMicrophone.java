public class HissingMicrophone {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        String a = io.getWord();
        int f = 0; //bool value
        for(int i = 0; i<a.length()-1; i++) {
            if(a.charAt(i) == 's') {
                if(a.charAt(i+1) == 's') {
                    f = 1;
                    break;
                }
            }
        }
        if(f == 0) {
            io.println("no hiss");
        } else {
            io.println("hiss");
        }
        io.flush();
    }
}