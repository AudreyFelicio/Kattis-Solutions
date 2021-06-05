#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int guess = 1;
  int counter = guess;
  bool opt = false;
  cout << guess << endl;
  while (true) {
    if (counter == 99) {
      break;
    }
    int optGuess;
    cin >> optGuess;
    if (opt) {
      counter += 3;
      cout << counter << endl;
      continue;
    }
    if (guess == 1 && (optGuess - counter) == 1) {
      guess = 1;
      opt = true;
    } else if (guess == 1 && (optGuess - counter) == 2) {
      guess = 2;
    } else if (guess == 2 && (optGuess - counter) == 1) {
      guess = 1;
    } else {
      guess = 2;
      opt = true;
    }
    counter = optGuess + guess;
    cout << counter << endl;
  }
}