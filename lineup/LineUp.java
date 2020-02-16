import java.util.*;

public class LineUp {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String[] inputs = new String[n];
        boolean isDecreasing = false;
        boolean isIncreasing = false;
        for(int i = 0; i < n; i++) {
            inputs[i] = in.next();
        }
        for(int i = 0; i < n - 1; i++) {
            if(inputs[i].compareTo(inputs[i+1]) < 0) {
                isIncreasing = true;
            } else {
                isDecreasing = true;
            }
        }
        if(isIncreasing && isDecreasing) {
            System.out.println("NEITHER");
        } else if (isIncreasing) {
            System.out.println("INCREASING");
        } else if (isDecreasing) {
            System.out.println("DECREASING");
        }
    }
}
