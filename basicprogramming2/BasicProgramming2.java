import java.util.*;
import java.io.*;

public class BasicProgramming2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        int[] numbers = new int[n];
        StringTokenizer number = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(number.nextToken());
        }
        if(t == 1) {
            Arrays.sort(numbers);
            int begin = 0;
            int end = n-1;
            while(begin != end) {
                if(numbers[begin] + numbers[end] < 7777) {
                    begin++;
                } else if (numbers[begin] + numbers[end] > 7777) {
                    end--;
                } else {
                    System.out.println("Yes");
                    break;
                }
            }
            if(begin == end) {
                System.out.println("No");
            }
        } else if (t == 2) {
            Arrays.sort(numbers);
            boolean containsDuplicate = false;
            for(int i = 0; i < n-1; i++) {
                if(numbers[i] == numbers[i+1]) {
                    containsDuplicate = true;
                    break;
                }
            }
            if(containsDuplicate) {
                System.out.println("Contains duplicate");
            } else {
                System.out.println("Unique");
            }
        } else if (t == 3) {
            Arrays.sort(numbers);
            int count = 1;
            int tempCount = 1;
            int current = numbers[0];
            int ans = numbers[0];
            for(int i = 1; i < n; i++) {
                if(current == numbers[i]) {
                    tempCount++;
                } else {
                    if(tempCount > count) {
                        ans = current;
                        count = tempCount;
                    }
                    tempCount = 1;
                    current = numbers[i];
                }
            }
            if(tempCount > count) {
                ans = current;
                count = tempCount;
            }
            if(count > n/2) {
                System.out.println(ans);
            } else {
                System.out.println(-1);
            }
        } else if (t == 4) {
            Arrays.sort(numbers);
            if(n % 2 == 1) {
                System.out.println(numbers[n/2]);
            } else {
                System.out.println(numbers[n/2 - 1] + " " + numbers[n/2]);
            }
        } else {
            Arrays.sort(numbers);
            int[] outputs = new int[n];
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(numbers[i] >= 100 && numbers[i] <= 999) {
                    outputs[count] = numbers[i];
                    count++;
                } else if (numbers[i] > 999) {
                    break;
                }
            }
            for(int i = 0; i < count; i++) {
                if(i == count - 1) {
                    System.out.print(outputs[i]);
                } else {
                    System.out.print(outputs[i] + " ");
                }
            }
        }
    }
}
