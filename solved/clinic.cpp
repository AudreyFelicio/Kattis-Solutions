#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k = 0;

struct Patient {
  ll arrival;
  string name;
  ll severity;
};

struct CompPatient {
  bool operator()(const Patient& p1, const Patient& p2) {
    ll priorityP1 = p1.severity - k * p1.arrival;
    ll priorityP2 = p2.severity - k * p2.arrival;
    if (priorityP1 != priorityP2) {
      return priorityP1 < priorityP2;
    } else {
      return p1.name > p2.name;
    }
  }
};

int main() {
  int n;
  cin >> n >> k;
  unordered_set<string> patients;
  priority_queue<Patient, vector<Patient>, CompPatient> pq;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      ll t, s;
      string m;
      cin >> t >> m >> s;
      pq.push({ t, m, s });
      patients.insert(m);
    } else if (q == 2) {
      ll t;
      cin >> t;
      if (pq.empty()) {
        cout << "doctor takes a break" << endl;
        continue;
      }
      bool found = false;
      while (true && !pq.empty()) {
        Patient curr = pq.top();
        pq.pop();
        if (patients.find(curr.name) != patients.end()) {
          cout << curr.name << endl;
          found = true;
          break;
        }
      }
      if (!found) {
        cout << "doctor takes a break" << endl;
      }
    } else {
      ll t;
      string m;
      cin >> t >> m;
      patients.erase(m);
    }
  }
}
