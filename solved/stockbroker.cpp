#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_SHARES 100000LL

ll days[400];

bool isValley(int index, int d) {
  ll curr = days[index];
  if (index == 0 && curr < days[index + 1]) {
    return true;
  } else if (index == d - 1 && curr < days[index - 1]) {
    return true;
  } else if (curr <= days[index - 1] && curr <= days[index + 1]) {
    return true;
  } else {
    return false;
  }
}

bool isPeak(int index, int d) {
  ll curr = days[index];
  if (index == 0 && curr > days[index + 1]) {
    return true;
  } else if (index == d - 1 && curr > days[index - 1]) {
    return true;
  } else if (curr >= days[index - 1] && curr >= days[index + 1]) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int d;
  cin >> d;
  for (int i = 0; i < d; i++) {
    cin >> days[i];
  }
  ll money = 100;
  ll shares = 0;
  if (d == 1) {
    cout << money << endl;
    return 0;
  }
  for (int i = 0; i < d; i++) {
    ll currPrice = days[i];
    bool peak = isPeak(i, d);
    bool valley = isValley(i, d);
    if (valley && i != d - 1) {
      ll buyAmount = min(MAX_SHARES - shares, money / currPrice);
      shares += buyAmount;
      money -= buyAmount * currPrice;
    }
    if (peak && i != 0) {
      money += shares * currPrice;
      shares = 0;
    }
  }
  cout << money << endl;
}