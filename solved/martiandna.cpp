#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dna[200005];
int occur[200005];

int main() {
  int n, k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < n; i++) {
    cin >> dna[i];
  }
  int acc = 0;
  for (int i = 0; i < r; i++) {
    int b, q;
    cin >> b >> q;
    occur[b] = q;
    acc += q;
  }
  int ans = 200005;
  int i = 0, j = 0;
  while (j < n) {
    if (occur[dna[j]] > 0) {
      acc--;
    }
    occur[dna[j]]--;
    while (i < j && occur[dna[i]] < 0) {
      occur[dna[i]]++;
      i++;
    }
    if (acc == 0) {
      ans = min(ans, j - i + 1);
    }
    j++;
  }
  if (ans == 200005) {
    cout << "impossible" << endl; 
  } else {
    cout << ans << endl;
  }
}