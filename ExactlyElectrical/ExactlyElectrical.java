import java.util.*;
import java.io.*;

public class ExactlyElectrical {
    public static void main(String[] args) throws IOException {    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st1.nextToken());
        int b = Integer.parseInt(st1.nextToken());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st2.nextToken());
        int d = Integer.parseInt(st2.nextToken());
        int t = Integer.parseInt(br.readLine());
        int manhattan = Math.abs(c - a) + Math.abs(d - b);
        if(t == 0) {
            if(manhattan == 0) {
                System.out.println('Y');
            } else {
                System.out.println('N');
            }
        } else {
            if( t < manhattan) {
                System.out.println('N');
            } else if( (manhattan - t) % 2 == 0) {
                System.out.println('Y');
            } else {
                System.out.println('N');
            }
        }
    }
}
