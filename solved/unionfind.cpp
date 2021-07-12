#include <bits/stdc++.h>
using namespace std;

int arr[1000030];
int ranking[1000030];

int findSet(int i) {
  return (arr[i] == i) ? i : (arr[i] = findSet(arr[i]));
}

void unionSet(int i, int j) {
  if (findSet(i) == findSet(j)) {
    return;
  }
  int x = findSet(i);
  int y = findSet(j);
  if (ranking[x] > ranking[y]) {
    swap(x, y);
  }
  arr[x] = y;
  if (ranking[x] == ranking[y]) {
    ranking[y]++;
  }
}

int main() {
  // Nasty problem
  // Need to buffer the output (don't use endl)
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  for (int i = 0; i < q; i++) {
    char sign;
    int a, b;
    cin >> sign >> a >> b;
    if (sign == '=') {
      unionSet(a, b);
    } else {
      if (findSet(a) == findSet(b)) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
  }
  cout << flush;
}
