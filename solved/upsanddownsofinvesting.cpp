#include <bits/stdc++.h>
using namespace std;
#define ll long long

int stocks[1005];

int main() {
  int s, n, m;
  cin >> s >> n >> m;
  for (int i = 0; i < s; i++) {
    cin >> stocks[i];
  }
  vector<int> peaks;
  vector<int> valleys;
  for (int i = 1; i < s - 1; i++) {
    if (stocks[i] > stocks[i - 1] && stocks[i] > stocks[i + 1]) {
      peaks.push_back(i);
    } else if (stocks[i] < stocks[i - 1] && stocks[i] < stocks[i + 1]) {
      valleys.push_back(i);
    }
  }
  bool isPeakFirst = (peaks.size() != 0 && valleys.size() != 0) ? peaks[0] < valleys[0] : peaks.size() > valleys.size();
  int peak = 0;
  int valley = 0;
  for (int i = 0; i < peaks.size(); i++) {
    if (isPeakFirst) {
      if (i == 0) {
        if (i == peaks.size() - 1 && i >= valleys.size()) {
          if (peaks[i] + 1 >= n && s - peaks[i] >= n) {
            peak++;
          }
          continue;
        }
        if (peaks[i] + 1 >= n && valleys[i] - peaks[i] + 1 >= n) {
          peak++;
        }
      } else if (i == peaks.size() - 1 && i >= valleys.size()) {
        if (peaks[i] - valleys[i - 1] + 1 >= n && s - peaks[i] >= n) {
          peak++;
        }
      } else {
        if (peaks[i] - valleys[i - 1] + 1 >= n && valleys[i] - peaks[i] + 1 >= n) {
          peak++;
        }
      }
    } else {
      if (i == peaks.size() - 1 && i + 1 >= valleys.size()) {
        if (peaks[i] - valleys[i] + 1 >= n && s - peaks[i] >= n) {
          peak++;
        }
      } else {
        if (peaks[i] - valleys[i] + 1 >= n && valleys[i + 1] - peaks[i] + 1 >= n) {
          peak++;
        }
      }
    }
  }
  for (int i = 0; i < valleys.size(); i++) {
    if (isPeakFirst) {
      if (i == valleys.size() - 1 && i + 1 >= peaks.size()) {
        if (valleys[i] - peaks[i] + 1 >= m && s - valleys[i] >= m) {
          valley++;
        }
      } else {
        if (valleys[i] - peaks[i] + 1 >= m && peaks[i + 1] - valleys[i] + 1 >= m) {
          valley++;
        }
      }
    } else {
      if (i == 0) {
        if (i == valleys.size() - 1 && i >= peaks.size()) {
          if (valleys[i] + 1 >= m && s - valleys[i] >= m) {
            valley++;
          }
          continue;
        }
        if (valleys[i] + 1 >= m && peaks[i] - valleys[i] + 1 >= m) {
          valley++;
        }
      } else if (i == valleys.size() - 1 && i >= peaks.size()) {
        if (valleys[i] - peaks[i - 1] + 1 >= m && s - valleys[i] >= m) {
          valley++;
        }
      } else {
        if (valleys[i] - peaks[i - 1] + 1 >= m && peaks[i] - valleys[i] + 1 >= m) {
          valley++;
        }
      }
    }
  }
  cout << peak << " " << valley << endl;
}