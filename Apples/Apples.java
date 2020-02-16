import java.util.*;
import java.io.*;

public class Apples {
    public static void handleColumn(char[][] arr, int r, int c) {
        int indexStart = 0;
        int indexEnd = 0;
        int countA = 0;
        for(int i = 0; i < r; i++) {
            if(arr[i][c] == 'a') {
                countA++;
                indexEnd++;
            } else if(arr[i][c] == '#') {
                for(int j = indexStart; j < indexEnd - countA; j++) {
                    arr[j][c] = '.';
                }
                for(int j = indexEnd - countA; j < indexEnd; j++) {
                    arr[j][c] = 'a';
                }
                indexEnd++;
                indexStart = indexEnd;
                countA = 0;
            } else {
                indexEnd++;
            }
        }
        for(int j = indexStart; j < indexEnd - countA; j++) {
            arr[j][c] = '.';
        }
        for(int j = indexEnd - countA; j < indexEnd; j++) {
            arr[j][c] = 'a';
        }    
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        char[][] table = new char[r][c];
        for(int i = 0; i < r; i++) {
            String line = br.readLine();
            for(int j = 0; j < line.length(); j++) {
                table[i][j] = line.charAt(j);
            }
        }
        for(int i = 0; i < c; i++) {
            handleColumn(table, r, i);
        }
        for(int i = 0; i < r; i++) {
            StringBuilder Line = new StringBuilder();
            for(int j = 0; j < c; j++) {
                Line.append(table[i][j]);
            }
            System.out.println(Line.toString());
        }
    }
}
