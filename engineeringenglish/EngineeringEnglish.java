public class EngineeringEnglish {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        String answer = "";
        String[] words = new String[20010];
        int counter = 0;
        while(io.hasMoreTokens()) {
            String a = io.getWord();
            String b = a.toLowerCase();
            int f = 0;
            for(int i = 0; i<counter; i++) {
                if(b.equals(words[i])) {
                    f = 1;
                    break;
                }
            }
            if(f == 0) {
                answer = answer + a + " ";
                words[counter] = b; 
                counter = counter + 1;
            } else {
                answer = answer + ". ";
                counter = counter + 1;
            }
            // io.println(answer);
        }
        io.println(answer);
        io.flush();
    }
}