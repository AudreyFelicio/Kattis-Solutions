#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll height[300100];

int main() {
  // Key Idea:
  // In a normal BST
  // If current node is inserted right, parent is predecessor, successor is higher up
  // If current node is inserted left, parent is successor, predecessor is higher up
  // We just take the max depth between successor and predecessor using above facts
  memset(height, 0, 300100);
  int n;
  cin >> n;
  set<ll> bst;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    bst.insert(x);
    ll currDepth = 0;
    auto it = bst.find(x);
    if (it != bst.begin()) {
      // predecessor exist
      it--;
      currDepth = max(currDepth, 1 + height[*it]);
    }
    it = bst.find(x);
    if (it != bst.end()) {
      it++;
      if (it != bst.end()) {
        // successor exist
        currDepth = max(currDepth, 1 + height[*it]);
      }
    }
    height[x] = currDepth;
    total += currDepth;
    cout << total << endl;
  }
}
