#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<string> hash;
  bool turn = 0;
  bool someoneLost = false;
  string prev = "";
  for (int i = 0; i < n; i++) {
    string guess;
    cin >> guess;
    if (someoneLost) {
      continue;
    }
    if (prev != "") {
      if (guess[0] != prev[prev.size() - 1]) {
        someoneLost = true;
      } else if (hash.find(guess) != hash.end()) {
        someoneLost = true;
      }
    }
    hash.insert(guess);
    if (!someoneLost) {
      prev = guess;
      turn = !turn;
    }
  }
  if (!someoneLost) {
    cout << "Fair Game" << endl;
  } else {
    cout << "Player " << (turn + 1) << " lost" << endl;
  }
}
