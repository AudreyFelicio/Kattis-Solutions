import java.util.*;
import java.io.*;

class Sorter {

    public static boolean isGreaterThan(String str1, String str2) {
        if( str1.charAt(0) < str2.charAt(0) ) {
            return true;
        } else if (str1.charAt(0) == str2.charAt(0) && str1.charAt(1) <= str2.charAt(1)) {
            return true;
        } else {
            return false;
        }
    }

    public static void mergeSortedArray(String[] arr, int startArr1, int endArr1, int startArr2, int endArr2) {
        String[] tempArr = new String[endArr2 - startArr1 + 1];
        int i = startArr1;
        int j = startArr2;
        int counter = 0;
        while(i <= endArr1 && j <= endArr2) {
            if(isGreaterThan(arr[i], arr[j])) {
                tempArr[counter] = arr[i];
                counter++;
                i++;
            } else {
                tempArr[counter] = arr[j];
                counter++;
                j++;
            }
        }
        if(j > endArr2) {
            while(i <= endArr1) {
                tempArr[counter] = arr[i];
                i++;
                counter++;
            }
        } else {
            while (j <= endArr2) {
                tempArr[counter] = arr[j];
                j++;
                counter++;
            }
        }
        //copy back to our original array
        int k = 0;
        for(int x = startArr1; x <= endArr2; x++) {
            arr[x] = tempArr[k];
            k++;
        }
    }

    public static void divideArray(String[] arr, int begin, int end) {
        int middle = begin + (end - begin)/2;
        if(end - begin < 1) {
            return;
        }
        divideArray(arr, begin, middle);
        divideArray(arr, middle+1, end);
        mergeSortedArray(arr, begin, middle, middle+1, end);
    }

    public static void sortStrings(String[] arr) {
        // TODO: implement your sorting function here
        divideArray(arr, 0, arr.length-1);
    }
}

class CustomCompare implements Comparator<String> {
    @Override
    public int compare(String a, String b) {
        if(a.charAt(0) > b.charAt(0)) {
            return 1;
        } else if (a.charAt(0) == b.charAt(0) && a.charAt(1) >= b.charAt(1)) {
            return 1;
        } else {
            return -1;
        }
    }
}

public class SortOfSorting {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = 0;
        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) {
                break;
            }
            if(cases > 0) {
                System.out.println();
            }
            //ArrayList<String> names = new ArrayList<String>();
            //for(int i = 0; i < n; i++) {
            //    names.add(br.readLine());
            //}
            //Collections.sort(names, new CustomCompare());
            //for(int i = 0; i < n; i++) {
            //    System.out.println(names.get(i));
            //}
            //cases++;
            String[] names = new String[n];
            for(int i = 0; i < n; i++) {
                names[i] = br.readLine();
            }
            Sorter help = new Sorter();
            help.sortStrings(names);
            for(int i = 0; i < n; i++) {
                System.out.println(names[i]);
            }
            cases++;
        }
    }
}
