#include <bits/stdc++.h>
using namespace std;
#define ll long long

int input[100005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << input[i] << endl;
  }
}