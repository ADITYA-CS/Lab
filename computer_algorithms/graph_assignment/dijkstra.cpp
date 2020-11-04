#include <bits/stdc++.h>
using namespace std;

vector<list<pair<int, int>>> g;
vector<int> distance;
vector<int> parent;
int n;

void Dijkstra(int source) {
  distance.resize(n, INT_MAX);
  parent.resize(n, -1);
  distance[source] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push({0, source});
  while (pq.size()) {
    int u = pq.top().second;
    int dis = -pq.top().first;
    pq.pop();
    if (dis != distance[u]) continue;

    for (auto e : g[u]) {
      int v = e.first;
      int w = e.second;
      if (dis + w < distance[v]) {
        parent[v] = u;
        distance[v] = dis + w;
        pq.push({-distance[v], v});
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
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
