#include <bits/stdc++.h>
using namespace std;

int table[705][705];
bool colored[705];
bool student[36];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      table[i][j] = s[j] - 'A';
    }
  }
  int colors = 0;
  for (int i = 0; i < k; i++) {
    bool hasNewColor = true;
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < n; l++) {
        if (table[l][j] == i) {
          if (colored[j]) {
            hasNewColor = false;
          } else {
            colored[j] = true;
            break;
          }
        }
      }
    }
    if (hasNewColor)
      colors++;
  }
  cout << colors << endl;
}