import java.util.*;
import java.io.*;

public class FlowLayout {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int totalWidth = 0;
            int totalHeight = 0;
            int currentHeight = 0;
            int currentWidth = 0;
            if(m == 0) {
                break;
            } else {
                while(true) {
                    StringTokenizer st2 = new StringTokenizer(br.readLine());
                    int width = Integer.parseInt(st2.nextToken());
                    int height = Integer.parseInt(st2.nextToken());
                    if(width == -1 && height == -1) {
                        break;
                    } else {
                        if(width + currentWidth > m) {
                            totalHeight += currentHeight;
                            currentHeight = height;
                            totalWidth = Math.max(totalWidth, currentWidth);
                            currentWidth = width;
                        } else {
                            currentWidth += width;
                            currentHeight = Math.max(currentHeight, height);
                        }
                    }
                }
                totalHeight += currentHeight;
                totalWidth = Math.max(totalWidth, currentWidth);
                System.out.println(totalWidth + " x " + totalHeight);
            }
        }
    }
}
