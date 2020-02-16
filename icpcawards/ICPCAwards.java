import java.util.*;
import java.io.*;

class Team {
    public String university;
    public String name;

    Team(String university, String name) {
        this.university = university;
        this.name = name;
    }

    @Override
    public String toString() {
        return this.university + " " + this.name;
    }
}

public class ICPCAwards {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Team[] teams = new Team[n];
        int countWinner = 0;
        for(int i = 0; i < n; i++) {
            if(countWinner == 12) {
                break;
            }
            StringTokenizer st = new StringTokenizer(br.readLine());
            String university = st.nextToken();
            String name = st.nextToken();
            boolean hasAward = false;
            teams[i] = new Team(university, name);
            for(int j = 0; j < i; j++) {
                if(university.equals(teams[j].university)) {
                    hasAward = true;
                    break;
                }
            }
            if(!hasAward) {
                System.out.println(teams[i]);
                countWinner++;
            }
        }
    }
}
