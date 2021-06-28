#include <bits/stdc++.h>
using namespace std;

int main() {
  int h;
  string path = "";
  cin >> h;
  string line;
  getline(cin, line);
  if (line.size() >= 2) {
    path = line.substr(1);
  }
  int minus = 1;
  for (int i = 0; i < path.size(); i++) {
    if (path[i] == 'L') {
      minus *= 2;
    } else {
      minus = minus * 2 + 1;
    }
  }
  cout << ((1 << (h + 1)) - minus) << endl;
}