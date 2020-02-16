import java.util.*;
import java.io.*;

public class FroshWeek {
    
    public static long mergeAndCount(int[] arr, int left1, int right1, int left2, int right2) {
        int[] tempArr = new int[right2-left1+1];
        long swaps = 0L;
        int i = left1;
        int j = left2;
        int count = 0;
        while(i <= right1 && j <= right2) {
            if(arr[i] > arr[j]) {
                swaps += right1 - i + 1; //if arr[i] is bigger, so is arr[i+1], ..., arr[right1]
                tempArr[count] = arr[j];
                j++;
                count++;
            } else {
                tempArr[count] = arr[i];
                i++;
                count++;
            }
        }
        if(i <= right1) {
            while(i <= right1) {
                tempArr[count] = arr[i];
                i++;
                count++;
            }
        } else {
            while(j <= right2) {
                tempArr[count] = arr[j];
                j++;
                count++;
            }
        }
        //copy to original array
        int k = left1;
        for(int x = 0; x < count; x++) {
            arr[k] = tempArr[x];
            k++;
        }
        return swaps;
    }

    public static long helpDivide(int[] arr, int begin, int end) {
        long swaps = 0L;
        if(end - begin < 1) {
            return 0;
        }
        int middle = begin + (end - begin)/2;
        swaps += helpDivide(arr, begin, middle);
        swaps += helpDivide(arr, middle+1, end);
        swaps += mergeAndCount(arr, begin, middle, middle+1, end);
        return swaps;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] numbers = new int[n];
        for(int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
        }
        System.out.println(helpDivide(numbers, 0, numbers.length-1));
    }
}
