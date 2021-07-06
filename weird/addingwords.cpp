#include <bits/stdc++.h>
using namespace std;

vector<string> parseInput(string s) {
  vector<string> out;
  string temp = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      temp += s[i];
    } else {
      out.push_back(temp);
      temp = "";
    }
  }
  out.push_back(temp);
  return out;
}

int main() {
  string s;
  unordered_map<string, int> map;
  unordered_map<int, string> reverse;
  while (getline(cin, s)) {
    vector<string> input = parseInput(s);
    if (input[0] == "def") {
      map[input[1]] = stoi(input[2]);
      reverse[stoi(input[2])] = input[1];
    } else if (input[0] == "calc") {
      string out = s.substr(5);
      bool unknown = false;
      int result = 0;
      bool isPlus = true;
      for (int i = 1; i < input.size(); i++) {
        string curr = input[i];
        if (curr == "+") {
          isPlus = true;
          continue;
        } else if (curr == "-") {
          isPlus = false;
          continue;
        } else if (curr == "=") {
          continue;
        }
        if (map.find(curr) == map.end()) {
          unknown = true;
          break;
        }
        int translate = map[curr];
        if (isPlus) {
          result += translate;
        } else {
          result -= translate;
        }
      }
      if (unknown) {
        out += " unknown";
      } else {
        if (reverse.find(result) == reverse.end()) {
          out += " unknown";
        } else {
          out += " " + reverse[result];
        }
      }
      cout << out << endl;
    } else {
      map.clear();
      reverse.clear();
    }
  }
}
