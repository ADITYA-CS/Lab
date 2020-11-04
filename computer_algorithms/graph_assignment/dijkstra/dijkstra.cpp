#include <bits/stdc++.h>
using namespace std;

vector<list<pair<int, int>>> g;
vector<int> dist;
vector<int> parent;
int n;

void Dijkstra(int source) {
  dist.resize(n, INT_MAX);
  parent.resize(n, -1);
  dist[source] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push({0, source});
  while (pq.size()) {
    int u = pq.top().second;
    int dis = -pq.top().first;
    pq.pop();
    if (dis != dist[u]) continue;

    for (auto e : g[u]) {
      int v = e.first;
      int w = e.second;
      if (dis + w < dist[v]) {
        parent[v] = u;
        dist[v] = dis + w;
        pq.push({-dist[v], v});
      }
    }
  }
}

void Path(int source, int destination) {
  if (parent[destination] == -1) {
    cout << "Cann't reach " << destination << " from " << source << endl;
    return;
  }

  int v = destination;
  stack<int> tmp;
  while (v != -1) {
    tmp.push(v);
    v = parent[v];
  }
  cout << "Path : ";
  while (tmp.size() != 1) {
    cout << tmp.top() << " --> ";
    tmp.pop();
  }
  cout << tmp.top() << endl;
}

int main() {
  cin >> n;
  int e;
  cin >> e;
  g.resize(n);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u == v) continue;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  Dijkstra(0);
  int destination = 86525;
  Path(0, destination);
}
