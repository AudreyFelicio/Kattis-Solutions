import java.util.*;
public class Tutorial {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        long m = io.getLong();
        long n = io.getLong();
        int t = io.getInt();
        if(t == 1) {
            boolean TLE = false;
            long numbers = 1;
            while(!TLE) {
                if(numbers > m) {
                    TLE = true;
                } else if(n > 1) {
                    numbers = n*numbers;
                    n = n-1;
                } else {
                    break;
                }
            }
            if(TLE) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        } else if (t == 2) {
            boolean TLE = false;
            long numbers = 1;
            while(!TLE) {
                if(numbers > m) {
                    TLE = true;
                } else if(n > 0) {
                    numbers = 2*numbers;
                    n = n-1;
                } else {
                    break;
                }
            }
            if(TLE) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        } else if (t == 3) {
            boolean TLE = false;
            long numbers = 1;
            int k = 4;
            while(!TLE) {
                if(numbers > m) {
                    TLE = true;
                } else if(k > 0) {
                    numbers = n*numbers;
                    k = k-1;
                } else {
                    break;
                }
            }
            if(TLE) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        } else if (t == 4) {
            boolean TLE = false;
            long numbers = 1;
            int k = 3;
            while(!TLE) {
                if(numbers > m) {
                    TLE = true;
                } else if(k > 0) {
                    numbers = n*numbers;
                    k = k-1;
                } else {
                    break;
                }
            }
            if(TLE) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        } else if (t == 5) {
            boolean TLE = false;
            long numbers = 1;
            int k = 2;
            while(!TLE) {
                if(numbers > m) {
                    TLE = true;
                } else if(k > 0) {
                    numbers = n*numbers;
                    k = k-1;
                } else {
                    break;
                }
            }
            if(TLE) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        } else if (t == 6) {
            boolean TLE = false;
            double numbers = n*Math.log(n)/Math.log(2);
            if(numbers > m) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        } else {
            if(n > m) {
                io.println("TLE");
            } else {
                io.println("AC");
            }
        }
        io.flush();
    }
}