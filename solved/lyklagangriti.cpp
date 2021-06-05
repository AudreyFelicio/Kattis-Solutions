#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
  char head;
  Node* next;
  Node* back;
};

void printNodes(Node* node) {
  Node* copy = node;
  string acc = "";
  while (copy != NULL) {
    acc += copy->head;
    copy = copy->next;
  }
  cout << acc << endl;
}

int main() {
  string s;
  cin >> s;
  Node* curr = new Node{ s[0], NULL, NULL };
  Node* prevPointer = curr;
  Node* currPointer = curr->next;
  for (int i = 1; i < s.length(); i++) {
    char currKey = s[i];
    if (currKey == 'L') {
      currPointer = prevPointer;
      prevPointer = prevPointer->back;
    } else if (currKey == 'R') {
      prevPointer = currPointer;
      currPointer = currPointer->next;
    } else if (currKey == 'B') {
      Node* newPrev = prevPointer->back;
      prevPointer->next = NULL;
      prevPointer->back = NULL;
      if (currPointer != NULL) {
        currPointer->back = newPrev;
      }
      prevPointer = newPrev;
      if (prevPointer == NULL) {
        curr = currPointer;
      } else {
        prevPointer->next = currPointer;
      }
    } else {
      Node* newNode = new Node{ currKey, NULL, NULL };
      newNode->next = currPointer;
      newNode->back = prevPointer;
      if (currPointer != NULL) {
        currPointer->back = newNode;
      }
      if (prevPointer != NULL) {
        prevPointer->next = newNode;
        prevPointer = prevPointer->next;
      } else {
        prevPointer = newNode;
        curr = prevPointer;
      }
    }
  }
  printNodes(curr);
}