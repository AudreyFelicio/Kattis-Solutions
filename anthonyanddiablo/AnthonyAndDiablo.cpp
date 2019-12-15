#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    double a,n;
    cin >> a >> n;
    double maxArea = (n*n)/(16*atan(1));
    if(a > maxArea) {
        cout << "Need more materials!" << endl;
    } else {
        cout << "Diablo is happy!" << endl;
    }
}