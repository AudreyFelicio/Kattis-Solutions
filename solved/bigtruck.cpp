#include <bits/stdc++.h>
using namespace std;
#define MAXDIST 100000000

struct edge {
  int distance;
  int from;
  int to;
};

struct path {
  int vertice;
  int distance;
  int items;
};

struct comparePath {
  bool operator()(path const& p1, path const& p2) {
    if (p1.distance != p2.distance) {
      return p1.distance > p2.distance;
    } else {
      return p2.items > p1.items;
    }
  }
};

vector<vector<edge> > graph;
int items[105];

int* djikstra(int n, int m) {
  // returns [distance, items]
  priority_queue<path, vector<path>, comparePath> pq;
  int* dist = new int[n];
  int* maxItems = new int[n];
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
    maxItems[i] = items[i];
    dist[i] = MAXDIST;
    visited[i] = false;
  }
  dist[0] = 0;
  pq.push({ 0, 0, items[0] });
  while (!pq.empty()) {
    path curr = pq.top();
    pq.pop();
    visited[curr.vertice] = true;
    int size = graph[curr.vertice].size();
    for (int i = 0; i < size; i++) {
      edge neighbour = graph[curr.vertice][i];
      if (visited[neighbour.to]) {
        continue;
      }
      if (dist[neighbour.from] + neighbour.distance < dist[neighbour.to]) {
        pq.push({
          neighbour.to,
          dist[neighbour.from] + neighbour.distance,
          maxItems[neighbour.from] + items[neighbour.to] 
        });
        dist[neighbour.to] = dist[neighbour.from] + neighbour.distance;
        maxItems[neighbour.to] = maxItems[neighbour.from] + items[neighbour.to];
      } else if (dist[neighbour.from] + neighbour.distance == dist[neighbour.to]) {
        pq.push({ 
          neighbour.to,
          dist[neighbour.from] + neighbour.distance,
          max(maxItems[neighbour.from] + items[neighbour.to], maxItems[neighbour.to]) 
        });
        dist[neighbour.to] = dist[neighbour.from] + neighbour.distance;
        maxItems[neighbour.to] = max(maxItems[neighbour.from] + items[neighbour.to], maxItems[neighbour.to]);
      }
    }
  }
  int* returnValue = new int[2];
  returnValue[0] = dist[n - 1];
  returnValue[1] = maxItems[n - 1];
  return returnValue;
}

int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> items[i];
    graph.push_back({});
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int from, to, distance;
    cin >> from >> to >> distance;
    graph[from - 1].push_back({ distance, from - 1, to - 1 });
    graph[to - 1].push_back({ distance, to - 1, from - 1 });
  }
  int* res = djikstra(n, m);
  if (res[0] == MAXDIST) {
    cout << "impossible" << endl;
  } else {
    cout << res[0] << " " << res[1] << endl;
  }
}