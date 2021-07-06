#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int count = 0;
  for (int i = 0; i < 26; i++) {
    if (count == b) {
      break;
    }
    for (int j = 0; j < 26; j++) {
      if (count == b) {
        break;
      }
      for (int k = 0; k < 26; k++) {
        if (count == b) {
          break;
        }
        for (int l = 0; l < 25; l++) {
          if (count == b) {
            break;
          }
          char first = i + 'a';
          char second = j + 'a';
          char third = k + 'a';
          char fourth = l + 'a';
          printf("%c%c%c%c ", first, second, third, fourth);
          count++;
        }
      }
    }
  }
  cout << endl;
}