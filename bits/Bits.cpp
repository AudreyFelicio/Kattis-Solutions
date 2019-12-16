#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    int t,x;
    cin >> t;
    for(int i = 0; i<t; i++) {
        cin >> x;
        int ans = 0;
        vector<int> typedIn;
        //generate all numbers typed in to the calculator digit by digit
        while(x/10 >= 1) {
            typedIn.push_back(x);
            x = x/10;
        }
        typedIn.push_back(x);
        //count the number of ones in binary representation
        for(int j = typedIn.size()-1; j>=0; j--) {
            int numberOfOnes = 0;
            while(typedIn[j] / 2 >= 1) {
                if(typedIn[j] % 2 == 1) {
                    numberOfOnes += 1;
                }
                typedIn[j] = typedIn[j]/2;
            }
            if(typedIn[j] == 1) {
                numberOfOnes += 1;
            }
            ans = max(ans, numberOfOnes);
        }
        cout << ans << endl;
    }
}