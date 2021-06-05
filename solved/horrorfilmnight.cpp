#include <bits/stdc++.h>
using namespace std;

bool p1[1000005];
bool p2[1000005];
int dp[1000005][2][2];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    p1[m] = true;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    p2[m] = true;
  }
  if (p1[999999] && p2[999999]) {
    dp[999999][1][1] = 1;
    dp[999999][0][1] = 1;
    dp[999999][1][0] = 1;
  } else if (p1[999999] && !p2[999999]) {
    dp[999999][1][1] = 1;
    dp[999999][0][1] = 1;
    dp[999999][1][0] = 0;
  } else if (!p1[999999] && p2[999999]) {
    dp[999999][1][1] = 1;
    dp[999999][0][1] = 0;
    dp[999999][1][0] = 1;
  } else {
    dp[999999][1][1] = 0;
    dp[999999][0][1] = 0;
    dp[999999][1][0] = 0;
  }
  for (int i = 999998; i >= 0; i--) {
    bool p1Watch = p1[i];
    bool p2Watch = p2[i];
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        if (j == 0 && k == 0) {
          continue;
        }
        if (p1Watch && p2Watch) {
          int watch = 1 + dp[i + 1][1][1];
          int dontWatch = dp[i + 1][j][k];
          dp[i][j][k] = max(watch, dontWatch);
        } else if (p1Watch && !p2Watch) {
          if (k) {
            int watch = 1 + dp[i + 1][1][0];
            int dontWatch = dp[i + 1][j][k];
            dp[i][j][k] = max(watch, dontWatch);
          } else {
            dp[i][j][k] = dp[i + 1][j][k];
          }
        } else if (!p1Watch && p2Watch) {
          if (j) {
            int watch = 1 + dp[i + 1][0][1];
            int dontWatch = dp[i + 1][j][k];
            dp[i][j][k] = max(watch, dontWatch);
          } else {
            dp[i][j][k] = dp[i + 1][j][k];
          }
        } else {
          dp[i][j][k] = dp[i + 1][j][k];
        }
      }
    }
  }
  cout << dp[0][1][1] << endl;
}