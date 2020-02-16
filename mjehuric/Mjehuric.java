import java.util.*;

public class Mjehuric {
    public static boolean checkSame(int[] woodPieces) {
        for(int i = 0; i < woodPieces.length; i++) {
            if(woodPieces[i] != i+1) {
                return false;
            }
        }
        return true;
    }

    public static void swap(int[] woodPieces, int i, int j) {
        int temp = woodPieces[i];
        woodPieces[i] = woodPieces[j];
        woodPieces[j] = temp;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] woodPieces = new int[5];
        for(int i = 0; i < 5; i++) {
            woodPieces[i] = in.nextInt();
        }
        int counter = 0;
        while(!checkSame(woodPieces)) {
            if(counter == 4) {
                counter = 0;
            } else {
                if(woodPieces[counter] > woodPieces[counter + 1]) {
                    swap(woodPieces, counter, counter + 1);
                    for(int i = 0; i < 5; i++) {
                        if(i == 4) {
                            System.out.println(woodPieces[i]);
                        } else {
                            System.out.print(woodPieces[i] + " ");
                        }
                    }
                }
                counter++;
            }
        }
    }
}
