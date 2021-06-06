#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Time {
  int minute;
  int second;
};

Time parseTime(string s) {
  string min = "";
  string sec = "";
  bool isMin = true;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ':') {
      isMin = false;
      continue;
    }
    if (isMin) {
      min += s[i];
    } else {
      sec += s[i];
    }
  }
  return { stoi(min), stoi(sec) };
}

int main() {
  int n;
  cin >> n;
  int homeScore = 0;
  int awayScore = 0;
  Time prevAway = { 0, 0 };
  Time prevHome = { 0, 0 };
  Time currAway = { 0, 0 };
  Time currHome = { 0, 0 };
  int homeTime = 0;
  int awayTime = 0;
  bool isHome = false;
  bool isTied = true;
  for (int i = 0; i < n; i++) {
    string name, time;
    int score;
    cin >> name >> score >> time;
    if (name == "A") {
      awayScore += score;
    } else {
      homeScore += score;
    }
    Time curr = parseTime(time);
    if (awayScore > homeScore) {
      if (isTied) {
        currHome = curr;
        currAway = curr;
        prevHome = curr;
        prevAway = curr;
      } else {
        if (!isHome) {
          currAway = curr;
        } else {
          currAway = curr;
          prevAway = curr;
          currHome = curr;
          homeTime += (currHome.minute - prevHome.minute) * 60 + currHome.second - prevHome.second;
        }
      }
      isTied = false;
      isHome = false;
    } else if (homeScore > awayScore) {
      if (isTied) {
        currHome = curr;
        currAway = curr;
        prevHome = curr;
        prevAway = curr;
      } else {
        if (isHome) {
          currHome = curr;
        } else {
          currHome = curr;
          prevHome = curr;
          currAway = curr;
          awayTime += (currAway.minute - prevAway.minute) * 60 + currAway.second - prevAway.second;
        }
      }
      isTied = false;
      isHome = true;
    } else {
      if (!isTied) {
        if (isHome) {
          currHome = curr;
          homeTime += (currHome.minute - prevHome.minute) * 60 + currHome.second - prevHome.second;
        } else {
          currAway = curr;
          awayTime += (currAway.minute - prevAway.minute) * 60 + currAway.second - prevAway.second;
        }
      }
      isTied = true;
      currHome = curr;
      currAway = curr;
      prevHome = curr;
      prevAway = curr;
    }
  }
  if (homeScore > awayScore) {
    currHome = { 32, 00 };
    homeTime += (currHome.minute - prevHome.minute) * 60 + currHome.second - prevHome.second;
    if (homeTime % 60 < 10 && awayTime % 60 < 10) {
      printf("H %d:0%d %d:0%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    } else if (homeTime % 60 < 10 && awayTime % 60 >= 10) {
      printf("H %d:0%d %d:%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    } else if (homeTime % 60 >= 10 && awayTime % 60 < 10) {
      printf("H %d:%d %d:0%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    } else {
      printf("H %d:%d %d:%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    }
  } else {
    currAway = { 32, 00 };
    awayTime += (currAway.minute - prevAway.minute) * 60 + currAway.second - prevAway.second;
    if (homeTime % 60 < 10 && awayTime % 60 < 10) {
      printf("A %d:0%d %d:0%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    } else if (homeTime % 60 < 10 && awayTime % 60 >= 10) {
      printf("A %d:0%d %d:%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    } else if (homeTime % 60 >= 10 && awayTime % 60 < 10) {
      printf("A %d:%d %d:0%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    } else {
      printf("A %d:%d %d:%d\n", homeTime / 60, homeTime % 60, awayTime / 60, awayTime % 60);
    }
  }
}