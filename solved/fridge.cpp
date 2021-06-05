#include <bits/stdc++.h>
using namespace std;

int digits[10];

int main() {
  string s;
  getline(cin, s);
  int minWithoutZero = 1001;
  for (int i = 0; i < s.length(); i++) {
    digits[s[i] - '0']++;
  }
  for (int i = 1; i < 10; i++) {
    minWithoutZero = min(minWithoutZero, digits[i]);
  }
  int zeroes = digits[0];
  string out = "";
  if (minWithoutZero > zeroes) {
    out += "1";
    for (int i = 0; i <= zeroes; i++) {
      out += "0";
    }
  } else {
    for (int i = 1; i < 10; i++) {
      if (minWithoutZero == digits[i]) {
        for (int j = 0; j <= minWithoutZero; j++) {
          out += to_string(i);
        }
        break;
      }
    }
  }
  cout << out << endl;
}