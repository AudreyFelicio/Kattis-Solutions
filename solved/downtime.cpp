#include <bits/stdc++.h>
using namespace std;

int requests[100005];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> requests[i];
  }
  int servers = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i = 0; i < n; i++) {
    int maxSize = servers * k;
    int start = requests[i];
    if (pq.empty()) {
      servers++;
    } else {
      int earliestEnd = pq.top();
      if (earliestEnd <= start) {
        pq.pop();
      } else {
        if (pq.size() >= maxSize) {
          servers++; 
        }
      }
    }
    pq.push(start + 1000);
  }
  cout << servers << endl;
}