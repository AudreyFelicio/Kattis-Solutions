#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int limit;

bool isVowel(char a) {
  return a == 'A' || a == 'I' || a == 'E' || a == 'O' || a == 'U';
}

ll backtrack(int index, bool containL, int consecutive, char prev) {
  if (consecutive >= 3) {
    return 0;
  }
  if (index == limit) {
    if (containL) {
      return 1;
    } else {
      return 0;
    }
  }
  char curr = s[index];
  if (curr != '_') {
    bool newLStatus = containL;
    if (curr == 'L') {
      newLStatus = true;
    }
    if (index == 0) {
      return backtrack(index + 1, newLStatus, 1, curr);
    } 
    bool isCurrVowel = isVowel(curr);
    bool isPrevVowel = isVowel(prev);
    if (isCurrVowel == isPrevVowel) {
      return backtrack(index + 1, newLStatus, consecutive + 1, curr);
    } else {
      return backtrack(index + 1, newLStatus, 1, curr);
    }
  } else {
    ll tryVowel, tryConsonant, tryL;
    if (index == 0) {
      tryVowel = 5 * backtrack(index + 1, false, 1, 'A');
      tryConsonant = 20 * backtrack(index + 1, false, 1, 'B');
      tryL = backtrack(index + 1, true, 1, 'L');
    } else {
      bool isPrevVowel = isVowel(prev);
      if (isPrevVowel) {
        tryVowel = 5 * backtrack(index + 1, containL, consecutive + 1, 'A');
        tryConsonant = 20 * backtrack(index + 1, containL, 1, 'B');
        tryL = backtrack(index + 1, true, 1, 'L');
      } else {
        tryVowel = 5 * backtrack(index + 1, containL, 1, 'A');
        tryConsonant = 20 * backtrack(index + 1, containL, consecutive + 1, 'B');
        tryL = backtrack(index + 1, true, consecutive + 1, 'L');
      }
    }
    return tryVowel + tryConsonant + tryL;
  }
}

int main() {
  cin >> s;
  limit = s.size();
  cout << backtrack(0, false, 0, -1) << endl;
}
