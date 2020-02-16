import java.util.*;
import java.io.*;

public class Recount {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        ArrayList<String> candidates = new ArrayList<String>();
        int maxCount = 1;
        int tempCount = 1;
        boolean unique = true;
        String candidate = null;
        String ans = null;
        while(true) {
            String name = br.readLine();
            if(name.equals("***")) {
                break;
            }
            candidates.add(name);
        }
        Collections.sort(candidates);
        candidate = candidates.get(0);
        for(int i = 1; i < candidates.size(); i++) {
            if(candidate.equals(candidates.get(i))) {
                tempCount++;
            } else {
                if(maxCount == tempCount) {
                    unique = false;
                } else if (tempCount > maxCount) {
                    ans = candidate;
                    maxCount = tempCount;
                }
                candidate = candidates.get(i);
                tempCount = 1;
            }
        }
        if(unique) {
            System.out.println(ans);
        } else {
            System.out.println("Runoff!");
        }
    }
}
