#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> tokenize;
  string acc = "";
  for (int i = 0; i < s.length(); i++) {
    char curr = s[i];
    if (curr == ';') {
      tokenize.push_back(acc);
      acc = "";
    } else {
      acc += curr;
    }
  }
  tokenize.push_back(acc);
  int ans = 0;
  for (int i = 0; i < tokenize.size(); i++) {
    string curr = tokenize[i];
    string begin = "";
    string end = "";
    bool isBegin = 1;
    for (int j = 0; j < curr.length(); j++) {
      if (curr[j] == '-') {
        isBegin = 0;
        continue;
      }
      if (isBegin) {
        begin += curr[j];
      } else {
        end += curr[j];
      }
    }
    if (isBegin) {
      ans += 1;
    } else {
      ans += stoi(end) - stoi(begin) + 1;
    }
  }
  cout << ans << endl;
}