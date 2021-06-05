#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge {
  int from;
  int to;
  int weight;
};

struct cmp {
  bool operator()(const pair<int, int> &p1, pair<int, int> &p2) const {
    return p1.second > p2.second;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adjList;
  for (int i = 0; i < n; i++) {
    adjList.push_back({});
  }
  for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    adjList[from - 1].push_back({ from - 1, to - 1, weight });
    adjList[to - 1].push_back({ to - 1, from - 1, weight });
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> djikstra;
  bool* visited = new bool[n];
  int* dist = new int[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    dist[i] = 100005;
  }
  djikstra.push({ 0, 0 });
  dist[0] = 0;
  while (!djikstra.empty()) {
    pair<int, int> curr = djikstra.top();
    djikstra.pop();
    visited[curr.first] = true;
    for (int i = 0; i < adjList[curr.first].size(); i++) {
      Edge currNeighbour = adjList[curr.first][i];
      if (visited[currNeighbour.to]) {
        continue;
      }
      if (dist[curr.first] + currNeighbour.weight < dist[currNeighbour.to]) {
        dist[currNeighbour.to] = dist[curr.first] + currNeighbour.weight;
        djikstra.push({ currNeighbour.to, dist[currNeighbour.to] });
      }
    }
  }
  cout << dist[n - 1] << endl;
}