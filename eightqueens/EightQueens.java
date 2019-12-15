import java.util.*;
public class EightQueens {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        char[][] board = new char[8][8];
        for(int i = 0; i<8; i++) {
            String s = io.getWord();
            char[] separate = s.toCharArray();
            for(int j = 0; j<8; j++) {
                board[i][j] = separate[j];
            }
        }
        boolean valid = true;
        int queens = 0;
        for(int i = 0; i<8; i++) {
            for(int j = 0; j<8; j++) {
                if(board[i][j] == '*') {
                    queens += 1;
                    //horizontal check
                    for(int k =0 ; k<8; k++) {
                        if(k != j && board[i][k] == '*') {
                            valid = false;
                            break;
                        }
                    }
                    //vertical check
                    for(int k = 0; k<8; k++) {
                        if(k != i && board[k][j] == '*') {
                            valid = false;
                            break;
                        }
                    }
                    //diagonal check 
                    for(int k = -7; k<8; k++) {
                        if(i+k >= 0 && i+k <= 7 && j+k <= 7 && j+k >= 0 && k != 0 && board[i+k][j+k] == '*') {
                            valid = false;
                            break;
                        } else if (i-k >= 0 && i-k <= 7 && j+k <= 7 && j+k >= 0 && k != 0 && board[i-k][j+k] == '*') {
                            valid = false;
                            break;
                        }
                    }
                }
            }
        }
        if(valid && queens == 8) {
            io.println("valid");
        } else {
            io.println("invalid");
        }
        io.flush();
    }
}