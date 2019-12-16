#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    if (n % 2 == 0) { //n even
        long long ans = (n/2 + 1)*(n/2 + 1); 
        cout << ans << endl;
    } else { //n odd
        long long ans = (n/2 + 1)*(n/2 + 2); 
        cout << ans << endl;
    }
}