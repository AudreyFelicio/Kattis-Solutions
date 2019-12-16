#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio;
    cin.tie(0);cout.tie(0);
    string toilets;
    cin >> toilets;
    string original = toilets;
    int ans = 0;
    //policy one
    for(int i = 0; i<toilets.length()-1; i++) {
        if(toilets.at(i+1) != toilets.at(i)) {
            ans += 1;
        }
        if(toilets.at(i+1) != 'U') {
            ans += 1;
            toilets.at(i+1) = 'U';
        }
    }
    cout << ans << endl;
    ans = 0;
    toilets = original;
    //policy two
    for(int i = 0; i<toilets.length()-1; i++) {
        if(toilets.at(i+1) != toilets.at(i)) {
            ans += 1;
        }
        if(toilets.at(i+1) != 'D') {
            ans += 1;
            toilets.at(i+1) = 'D';
        }
    }
    cout << ans << endl;
    ans = 0;
    toilets = original;
    //policy three
    for(int i = 0; i<toilets.length()-1; i++) {
        if(toilets.at(i+1) != toilets.at(i)) {
            ans += 1;
        }
    }
    cout << ans << endl;
}