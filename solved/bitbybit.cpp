#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    char state[32];
    for (int i = 0; i < 32; i++) {
      state[i] = '?';
    }
    for (int i = 0; i < n; i++) {
      string ins;
      int index, index2;
      cin >> ins;
      if (ins == "SET") {
        cin >> index;
        state[31 - index] = '1';
      } else if (ins == "CLEAR") {
        cin >> index;
        state[31 - index] = '0';
      } else if (ins == "OR") {
        cin >> index >> index2;
        if (state[31 - index] == '1' || state[31 - index2] == '1') {
          state[31 - index] = '1';
        } else if (state[31 - index] == '0' && state[31 - index2] == '0') {
          state[31 - index] = '0';
        } else {
          state[31 - index] = '?';
        }
      } else {
        cin >> index >> index2;
        if (state[31 - index] == '0' || state[31 - index2] == '0') {
          state[31 - index] = '0';
        } else if (state[31 - index] == '1' && state[31 - index2] == '1') {
          state[31 - index] = '1';
        } else {
          state[31 - index] = '?';
        }
      }
    }
    for (int i = 0; i < 32; i++) {
      cout << state[i];
    }
    cout << endl;
  }
}