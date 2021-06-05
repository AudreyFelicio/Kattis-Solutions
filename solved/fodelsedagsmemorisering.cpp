#include <bits/stdc++.h>
using namespace std;

struct Person {
  string name;
  int like;
};

Person birthday[50][50];

vector<string> tokenize(string line) {
  vector<string> out;
  string acc = "";
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == ' ') {
      out.push_back(acc);
      acc = "";
    } else {
      acc += line[i];
    }
  }
  out.push_back(acc);
  return out;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  string newline;
  getline(cin, newline);
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    vector<string> tokens = tokenize(line);
    string bday = tokens[2];
    int day = stoi(bday.substr(0, 2));
    int month = stoi(bday.substr(3, 2));
    int currLike = stoi(tokens[1]);
    if (birthday[day][month].name == "") {
      birthday[day][month] = { tokens[0], currLike };
      ans++;
    } else {
      if (currLike > birthday[day][month].like) {
        birthday[day][month] = { tokens[0], currLike };
      }
    }
  }
  cout << ans << endl;
  vector<string> names;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (birthday[i][j].name != "") {
        names.push_back(birthday[i][j].name);
      }
    }
  }
  sort(names.begin(), names.end());
  for (int i = 0; i < names.size(); i++) {
    cout << names[i] << endl;
  }
}