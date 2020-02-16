import java.util.*;
import java.io.*;

class Restaurant {
    public String name;
    public ArrayList<String> menu = new ArrayList<String>();
    
    Restaurant(String name) {
        this.name = name;
    }

    public void addMenu(String menu) {
        this.menu.add(menu);
    }

    public boolean findMenu() {
        boolean pancake = false;
        boolean pea = false;
        for(int i = 0; i < this.menu.size(); i++) {
            if(this.menu.get(i).equals("pea soup")) {
                pea = true;
            }
            if(this.menu.get(i).equals("pancakes")) {
                pancake = true;
            }
        }
        return pancake && pea;
    }

}

public class PeaSoup {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean available = false;
        ArrayList<Restaurant> list = new ArrayList<Restaurant>();
        for(int i = 0; i < n; i++) {
            int k = Integer.parseInt(br.readLine());
            for(int j = 0; j < k+1; j++) {
                if(j == 0) {
                    list.add(new Restaurant(br.readLine()));
                } else {
                    list.get(i).addMenu(br.readLine());
                }
            }
            if(list.get(i).findMenu() && !available) {
                available = true;
                System.out.println(list.get(i).name);
            }
        }
        if(!available) {
            System.out.println("Anywhere is fine I guess");
        }
    }
}
