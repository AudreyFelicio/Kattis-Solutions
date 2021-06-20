#include <bits/stdc++.h>
using namespace std;

int main() {
  string n, m;
  cin >> n >> m;
  string ans = "";
  if (m == "1") {
    cout << n << endl;
    return 0;
  }
  if (m.size() >= n.size() + 1) {
    ans += "0";
    ans += ".";
    for (int i = 0; i < m.size() - n.size() - 1; i++) {
      ans += "0";
    }
    int lastZeroIndex = -1;
    for (int i = n.size() - 1; i >= 0; i--) {
      if (n[i] == '0') {
        lastZeroIndex = i;
      } else {
        break;
      }
    }
    if (lastZeroIndex == -1) {
      ans += n;
    } else {
      for (int i = 0; i < lastZeroIndex; i++) {
        ans += n[i];
      }
    }
  } else {
    for (int i = 0; i < n.size() - m.size() + 1; i++) {
      ans += n[i];
    }
    int lastZeroIndex = -1;
    for (int i = n.size() - 1; i >= n.size() - m.size() + 1; i--) {
      if (n[i] == '0') {
        lastZeroIndex = i;
      } else {
        break;
      }
    }
    if (lastZeroIndex == -1) {
      ans += ".";
      for (int i = n.size() - m.size() + 1; i < n.size(); i++) {
        ans += n[i];
      }
    } else if (lastZeroIndex == n.size() - m.size() + 1) {
      // do nothing
    }
     else {
      ans += ".";
      for (int i = n.size() - m.size() + 1; i < lastZeroIndex; i++) {
        ans += n[i];
      }
    }
  }
  cout << ans << endl;
}