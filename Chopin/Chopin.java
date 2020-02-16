import java.util.*;
import java.io.*;

public class Chopin {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int i = 1;
        while((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            String key = st.nextToken();
            String melody = st.nextToken();
            boolean alternate = false;
            if(key.equals("A#")) {
                key = "Bb";
                alternate = true;
            } else if (key.equals("Bb")) {
                key = "A#";
                alternate = true;
            } else if (key.equals("C#")) {
                key = "Db";
                alternate = true;
            } else if (key.equals("Db")) {
                key = "C#";
                alternate = true;
            } else if (key.equals("D#")) {
                key = "Eb";
                alternate = true;
            } else if (key.equals("Eb")) {
                key = "D#";
                alternate = true;
            } else if (key.equals("F#")) {
                key = "Gb";
                alternate = true;
            } else if (key.equals("Gb")) {
                key = "F#";
                alternate = true;
            } else if (key.equals("G#")) {
                key = "Ab";
                alternate = true;
            } else if (key.equals("Ab")) {
                key = "G#";
                alternate = true;
            }
            if(alternate) {
                System.out.println("Case " + i + ": " + key + " " + melody);
            } else {
                System.out.println("Case " + i + ": UNIQUE");
            }
            i++;
        }
    }
}
