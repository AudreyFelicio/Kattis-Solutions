#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int x = (((n - m) % n) + n) % n;
  int normal = (m - n + x) / n;
  int plusOne = normal + 1;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < normal; j++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 0; i < n - x; i++) {
    for (int j = 0; j < plusOne; j++) {
      cout << "*";
    }
    cout << endl;
  }
}