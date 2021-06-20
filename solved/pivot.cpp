#include <bits/stdc++.h>
using namespace std;

int maxPrefix[100005];
int minSuffix[100005];
int arr[100005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int maxSoFar = arr[0];
  int minSoFar = arr[n - 1];
  for (int i = 0; i < n; i++) {
    maxSoFar = max(maxSoFar, arr[i]);
    maxPrefix[i] = maxSoFar;
  }
  for (int i = n - 1; i >= 0; i--) {
    minSoFar = min(minSoFar, arr[i]);
    minSuffix[i] = minSoFar;
  }
  int count = 0;
  if (arr[0] < minSuffix[1]) {
    count++;
  }
  if (arr[n - 1] > maxPrefix[n - 2]) {
    count++;
  }
  for (int i = 1; i <= n - 2; i++) {
    if (arr[i] < minSuffix[i + 1] && arr[i] > maxPrefix[i - 1]) {
      count++;
    }
  }
  cout << count << endl;
}