public class Everywhere {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int t = io.getInt();
        for(int i = 0; i<t; i++) {
            int n = io.getInt();
            String[] countries = new String[n];
            int counter = 0;
            for(int j = 0; j<n; j++) {
                String a = io.getWord();
                int f = 0;
                for (int k = 0; k<n; k++) {
                    if(a.equals(countries[k])) {
                        f = 1;
                    }
                }
                if(f == 0) {
                    countries[counter] = a;
                    counter += 1;
                } 
            }
            io.println(counter);
        }
        io.flush();
    }
}