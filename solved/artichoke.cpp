#include <bits/stdc++.h>
using namespace std;

int main() {
  double p, a, b, c, d;
  int n;
  cin >> p >> a >> b >> c >> d >> n;
  double currMax = p * (sin(a + b) + cos(c + d) + 2);
  double ans = -1e9;
  for (int i = 1; i <= n; i++) {
    double curr = p * (sin(a * i + b) + cos(c * i + d) + 2);
    if (currMax >= curr) {
      ans = max(ans, currMax - curr);
    } else {
      currMax = curr;
    }
  }
  cout << setprecision(9) << ans << endl;
}