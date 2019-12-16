#include <bits/stdc++.h>
using namespace std;
int main() {
    ios:: sync_with_stdio;
    cin.tie(0);cout.tie(0);
    int h,v;
    cin >> h >> v;
    double pi = atan(1)*4;
    double angleInRadian = v*pi/180;
    if(v >= 0 && v <= 180) { //santa does not fall to ground
        cout << "safe" << endl;
    } else {
        cout << floor(abs(h/sin(angleInRadian))) << endl; //trigonometry
    }
}