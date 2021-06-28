#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  while (cin >> line) {
    int prev = 0;
    int total = 0;
    int n = line.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
      total += line[i] - '0';
    }
    if (total % n != 0) {
      cout << line << ": invalid # of balls" << endl;
      continue; 
    }
    int balls = total / n;
    int loops = 0;
    int time = 1;
    bool error = false;
    while (loops < 10) {
      for (int i = 0; i < n; i++) {
        int height = line[i] - '0';
        if (pq.empty()) {
          if (height == 0) {
            time++;
            continue;
          } else if (balls) {
            pq.push(time + height);
            balls--;
          } else {
            error = true;
            break;
          }
          time++;
          continue;
        }
        int nearestFall = pq.top();
        if (height == 0 && nearestFall <= time) {
          error = true;
          break;
        } else if (height == 0) {
          time++;
          continue;
        } else if (nearestFall == time) {
          pq.pop();
          pq.push(nearestFall + height);
        } else if (nearestFall < time) {
          error = true;
          break;
        } else {
          // time < nearestFall
          if (balls) {
            // throw new ball
            pq.push(time + height);
            balls--;
          } else {
            error = true;
            break;
          }
        }
        time++;
      }
      loops++;
      if (error) {
        break;
      }
    }
    if (error) {
      cout << line << ": invalid pattern" << endl;
    } else {
      cout << line << ": valid with " << (total / n) << " balls" << endl;
    }
  }
}
