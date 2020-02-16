import java.util.*;

class Binary {
    public String number;
    public int length;

    Binary(String number, int length) {
        this.number = number;
        this.length = length;
    }   
}

public class Base2Palindrome {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        Binary[] dp = new Binary[4*m];
        dp[0] = new Binary("0",1);
        dp[1] = new Binary("1",1);
        dp[2] = new Binary("00",2);
        dp[3] = new Binary("11",2);
        int currentLength = 3;
        int k = 0;
        for(int i = 4; i < 2*m; i++) {
            if(k > 0 && dp[k].length == dp[k-1].length - 1) {
                currentLength++;
            }            
            if(dp[i-1].length == currentLength - 1) {
                StringBuilder zero = new StringBuilder();
                for(int j = 0; j < currentLength; j++) {
                    zero.append("0");
                }
                dp[i] = new Binary(zero.toString(), currentLength);
            } else {
                StringBuilder number = new StringBuilder();
                number.append("1");
                number.append(dp[k].number);
                number.append("1");
                dp[i] = new Binary(number.toString(), currentLength);
                k++;
            }
        }
        //scan again to find mth nonzero binary
        int scan = 0;
        String theAnswer = "lala";
        for(int i = 0; i < 2*m; i++) {
            if(scan == m) {
                theAnswer = dp[i-1].number;
                break;
            }
            if(dp[i].number.charAt(0) != '0') {
                scan++;
            }
        }
        System.out.println(theAnswer);
    }
}
