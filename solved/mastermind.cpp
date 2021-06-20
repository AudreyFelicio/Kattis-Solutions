#include <bits/stdc++.h>
using namespace std;

int freq[30];
bool visited[100];

int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    freq[a[i] - 'A']++;
  }
  int r = 0;
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      r++;
      freq[a[i] - 'A']--;
      visited[i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (freq[b[i] - 'A'] > 0 && !visited[i]) {
      s++;
      freq[b[i] - 'A']--;
    }
  }
  cout << r << " " << s << endl;
}