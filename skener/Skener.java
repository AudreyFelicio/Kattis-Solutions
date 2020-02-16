import java.util.*;
import java.io.*;

public class Skener {
    public static void main(String[] args) throws IOException {    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int zr = Integer.parseInt(st.nextToken());
        int zc = Integer.parseInt(st.nextToken());
        char[][] input = new char[r][c];
        char[][] ans = new char[r*zr][c*zc];
        for(int i = 0; i < r; i++) {
            String line = br.readLine();
            for(int j = 0; j < line.length(); j++) {
                input[i][j] = line.charAt(j);
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                char current = input[i][j];
                for(int x = zr*i; x < zr*i + zr; x++) {
                    for(int y = zc*j; y < zc*j + zc; y++) {
                        ans[x][y] = current;
                    }
                }
            }
        }
        for(int i = 0; i < r*zr; i++) {
            for(int j = 0; j < c*zc; j++) {
                System.out.print(ans[i][j]);
            }
            if(i != r*zr - 1) {
                System.out.println();
            }
        }
    }

}
