public class GuessingGame {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int[] guesses = new int[2501];
        int counter = 0;
        int prevcounter = 0;
        String[] facts = new String[2501];
        while(io.hasMoreTokens()) {
            int a = io.getInt();
            if(a == 0) {
                break;
            } else {
                String b = io.getWord();
                String c = io.getWord();
                String guess = b + " " + c;
                if(guess.equals("right on")) {
                    guesses[counter] = a;
                    facts[counter] = guess;
                    boolean bool = false;
                    for(int i = prevcounter; i <counter; i++) {
                        if(facts[i].equals("too high")) {
                            if(a < guesses[i]) {
                                bool = false;
                            } else {
                                bool = true;
                                break;
                            }
                        } else if (facts[i].equals("too low")) {
                            if(a > guesses[i]) {
                                bool = false;
                            } else {
                                bool = true;
                                break;
                            }
                        }
                    }
                    counter = counter+1;
                    prevcounter = counter;
                    if(bool) {
                        io.println("Stan is dishonest");
                    } else {
                        io.println("Stan may be honest");
                    }
                } else {
                    guesses[counter] = a;
                    facts[counter] = guess;
                    counter = counter + 1;
                }
            }
            
        }
        io.flush();
    }
}