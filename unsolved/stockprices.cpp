#include <bits/stdc++.h>
using namespace std;

struct Stock {
  int num;
  int price;
};

struct BuyComp {
  bool operator()(const Stock& s1, const Stock& s2) {
    return s1.price < s2.price;
  }
};

struct SellComp {
  bool operator()(const Stock& s1, const Stock& s2) {
    return s1.price > s2.price;
  }
};

int main() {
  int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    priority_queue<Stock, vector<Stock>, BuyComp> buy;
    priority_queue<Stock, vector<Stock>, SellComp> sell;
    while (n) {
      string command;
      int num, price;
      string waste;
      cin >> command >> num >> waste >> waste >> price;
      int stockPrice = -1;
      if (command == "buy") {
        buy.push({ num, price });
      } else {
        sell.push({ num, price });
      }
      if (!sell.empty() && !buy.empty()) {
        Stock largestBid = buy.top();
        Stock lowestSell = sell.top();
        while (largestBid.price >= lowestSell.price) {
          stockPrice = lowestSell.price;
          sell.pop();
          buy.pop();
          if (largestBid.num > lowestSell.num) {
            buy.push({ largestBid.num - lowestSell.num, largestBid.price });
          } else if (largestBid.num < lowestSell.num) {
            sell.push({ lowestSell.num - largestBid.num, lowestSell.price });
          }
          if (buy.empty() || sell.empty()) {
            break;
          }
          largestBid = buy.top();
          lowestSell = sell.top();
        }
      }
      printf("%s %s %s\n", 
        sell.empty() ? "-" : to_string(sell.top().price).c_str(),
        buy.empty() ? "-" : to_string(buy.top().price).c_str(),
        stockPrice == -1 ? "-" : to_string(stockPrice).c_str()
      );
      n--;
    }
    t--;
  }
}
