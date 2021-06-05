#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

pair<long double, long double> segments[1005];

long double computeTime(long double predicted, int n) {
    long double time = 0.0;
    for (int i = 0; i < n; i++) {
        long double distance = segments[i].first;
        long double speed = segments[i].second + predicted;
        time += distance / speed;
    }
    return time;
}

int main() {
    int n;
    long double t;
    cin >> n >> t;
    long double min = 1e6;
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
        if (segments[i].second < min) {
            min = segments[i].second;
        }
    }
    min = -min;
    long double max = 1e7;
    long double c;
    long double time = t + 1;
    int iterations = 0;
    while (abs(time - t) > 0.000000001 && iterations < 1500) {
        c = (min + max) / 2;
        time = computeTime(c, n);
        if (time > t) {
            // need to go faster
            min = c;
        } else {
            // need to go slower
            max = c;
        }
        iterations++;
    }
    cout << setprecision(9) << c << endl;
}