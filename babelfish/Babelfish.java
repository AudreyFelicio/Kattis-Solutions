import java.util.*;
import java.io.*;

class Dictionary {
    public String english;
    public String babel;

    Dictionary(String english, String babel) {
        this.english = english;
        this.babel = babel;
    }
}   

class sortDictionary implements Comparator<Dictionary> {
    @Override
    public int compare(Dictionary d1, Dictionary d2) {
        return d1.babel.compareTo(d2.babel);
    }
}

public class Babelfish {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Dictionary> words = new ArrayList<Dictionary>();
        String line = null;
        while( !(line = br.readLine()).equals("") ) {
            StringTokenizer st = new StringTokenizer(line);
            String english = st.nextToken();
            String babel = st.nextToken();
            words.add(new Dictionary(english, babel));
        }
        Collections.sort(words, new sortDictionary());
        while(br.ready()) {
            //binary search for english word
            String word = br.readLine();
            int begin = 0;
            int end = words.size() - 1;
            boolean found = false;
            while(begin <= end) {
                int middle = begin + (end - begin)/2;
                if(word.compareTo(words.get(middle).babel) > 0) {
                    begin = middle + 1;
                } else if (word.compareTo(words.get(middle).babel) < 0) {
                    end = middle - 1;
                } else {
                    System.out.println(words.get(middle).english);
                    found = true;
                    break;
                }
            }
            if(!found) {
                System.out.println("eh");
            }
        }
    }   
}
