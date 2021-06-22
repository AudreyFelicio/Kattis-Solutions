#include <bits/stdc++.h>
using namespace std;

struct Person {
  string name;
  int ranking[10];
};

Person parsePerson(string name, string rank) {
  Person person = {};
  person.name = name.substr(0, name.size() - 1);
  int index = 0;
  string curr = "";
  for (int i = rank.size() - 1; i >= 0; i--) {
    if (rank[i] != '-') {
      curr += rank[i];
      continue;
    }
    if (curr == "reppu") {
      person.ranking[index] = 3;
    } else if (curr == "elddim") {
      person.ranking[index] = 2;
    } else {
      person.ranking[index] = 1;
    }
    curr = "";
    index++;
  }
  if (curr == "reppu") {
    person.ranking[index] = 3;
  } else if (curr == "elddim") {
    person.ranking[index] = 2;
  } else {
    person.ranking[index] = 1;
  }
  for (int i = index + 1; i < 10; i++) {
    person.ranking[i] = 2;
  }
  return person;
}

bool cmp(Person a, Person b) {
  for (int i = 0; i < 10; i++) {
    if (a.ranking[i] != b.ranking[i]) {
      return a.ranking[i] < b.ranking[i];
    }
  }
  return a.name > b.name;
}

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    Person* people = new Person[n];
    for (int j = 0; j < n; j++) {
      string name;
      string rank;
      string consume;
      cin >> name >> rank >> consume;
      people[j] = parsePerson(name, rank);
    }
    sort(people, people + n, cmp);
    for (int j = n - 1; j >= 0; j--) {
      cout << people[j].name << endl;
    }
    cout << "==============================" << endl;
  }
}