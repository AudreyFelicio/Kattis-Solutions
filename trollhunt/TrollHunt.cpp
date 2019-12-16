#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    int b,k,g;
    cin >> b >> k >> g;
    int groupOfKnights = k/g;
    double days = (float)(b-1)/groupOfKnights;
    cout << ceil(days) << endl;
}