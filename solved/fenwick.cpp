#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define LSOne(S) ((S) & -(S))

ll fenwick[5000050];
int n, q;

ll rsq(int i) {
  ll sum = 0;
  for (; i; i -= LSOne(i)) {
    sum += fenwick[i];
  }
  return sum;
}

void update(int i, ll v) {
  for (; i <= n; i += LSOne(i)) {
    fenwick[i] += v;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    char sign;
    int a;
    ll b;
    cin >> sign >> a;
    if (sign == '+') {
      cin >> b;
      update(a + 1, b);
    } else {
      cout << rsq(a) << "\n";
    }
  }
  cout << flush;
}
