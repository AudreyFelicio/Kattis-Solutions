#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> lastSeen;
  int min = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (lastSeen.find(x) != lastSeen.end()) {
      min = std::min(min, i - lastSeen[x]);
    }
    lastSeen[x] = i;
  }
  cout << min << endl;
}
