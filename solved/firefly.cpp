#include <bits/stdc++.h>
using namespace std;

int stalagmites[100005];
int stalactites[100005];
int trials[500005];

int searchForStalagmite(int height, int n) {
  int min = 0;
  int max = n;
  while (min < max) {
    int mid = (min + max) / 2;
    if (stalagmites[mid] >= height) {
      max = mid;
    } else {
      min = mid + 1;
    }
  }
  return min;
}

int searchForStalactite(int height, int n, int h) {
  int min = 0;
  int max = n;
  while (min < max) {
    int mid = (min + max) / 2;
    int hit = h - stalactites[mid];
    if (hit < height) {
      max = mid;
    } else {
      min = mid + 1;
    }
  }
  return min;
}

int main() {
  int n, h;
  cin >> n >> h;
  for (int i = 0; i < n / 2; i++) {
    cin >> stalagmites[i] >> stalactites[i];
  }
  sort(stalagmites, stalagmites + n / 2);
  sort(stalactites, stalactites + n / 2);
  int min = n;
  for (int i = 1; i <= h; i++) {
    int hitStalagmite = (n / 2) - searchForStalagmite(i, n / 2);
    int hitStalactite = (n / 2) - searchForStalactite(i, n / 2, h);
    min = std::min(min, hitStalactite + hitStalagmite);
    trials[i] = hitStalagmite + hitStalactite;
  }
  int count = 0;
  for (int i = 1; i <= h; i++) {
    if (trials[i] == min)
      count++;
  }
  cout << min << " " << count << endl;
}