import java.util.*;
import java.io.*;

public class Apaxiaaans {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < input.length() - 1; i++) {
            if(input.charAt(i) != input.charAt(i+1)) {
                ans.append(input.charAt(i));
            }
        }
        ans.append(input.charAt(input.length() - 1));
        System.out.println(ans.toString());
    }
}
