#include <bits/stdc++.h>
using namespace std;

#define HASHTAG '#'
#define DOT '.'

char getReverseSymbol(char symbol) {
  if (symbol == HASHTAG) {
    return DOT;
  } else {
    return HASHTAG;
  }
}

string processLine(string s, int* lineSize, bool* error) {
  s += ' ';
  string line;
  string acc;
  string tokenize[s.length()];
  int tokenizeSize = 0;
  char symbol = s[0];
  for (int i = 2; i < s.length(); i++) {
    if (s[i] == ' ') {
      tokenize[tokenizeSize] = acc;
      acc = "";
      tokenizeSize++;
    } else {
      acc += s[i];
    }
  }
  int totalSize = 0;
  for (int i = 0; i < tokenizeSize; i++) {
    int num = stoi(tokenize[i]);
    for (int j = 0; j < num; j++) {
      line += symbol;
    }
    symbol = getReverseSymbol(symbol);
    totalSize += num;
  }
  if (*lineSize == -1) {
    *lineSize = totalSize;
  } else if (*lineSize != totalSize) {
    *error = true;
  }
  return line + "\n";
}

int main() {
  int n;
  int lineSize = -1;
  bool error = false;
  string newline;
  string accOut = "";
  cin >> n;
  getline(cin, newline);
  while (true) {
    if (n == 0) {
      break;
    }
    string s;
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      accOut += processLine(s, &lineSize, &error);
    }
    if (error) {
      accOut += "Error decoding image\n";
    }
    error = false;
    lineSize = -1;
    cin >> n;
    getline(cin, newline);
    if (n == 0) {
      break;
    }
    accOut += "\n";
  }
  cout << accOut;
}