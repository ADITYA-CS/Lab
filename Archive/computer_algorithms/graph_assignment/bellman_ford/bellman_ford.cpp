#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
};
vector<Edge> g;
vector<int> dist, parent;
int n, e;
const int INF = INT_MAX;

bool BellmanFord(int source) {
  dist.assign(n, INF);
  parent.assign(n, -1);
  dist[source] = 0;
  bool cycle;
  bool move;
  for (int i = 0; i < n; i++) {
    cycle = false;
    move = false;
    for (int j = 0; j < e; j++) {
      int u = g[j].u;
      int v = g[j].v;
      int w = g[j].w;
      if (dist[u] < INF) {
        if (dist[v] > dist[u] + w) {
          parent[v] = u;
          dist[v] = dist[u] + w;
          cycle = true;
          move = true;
        }
      }
    }
    if (move && i != n - 1) return false;
  }
  return cycle;
}

void Path(int source, int destination) {
  if (parent[destination] == -1) {
    cout << "Cann't reach " << destination << " from " << source << endl;
    return;
  }
  stack<int> tmp;
  int x = destination;
  while (x != -1) {
    tmp.push(x);
    x = parent[x];
  }
  cout << "Path : ";
  while (tmp.size() != 1) {
    cout << tmp.top() << " --> ";
    tmp.pop();
  }
  cout << tmp.top() << endl;
}

int main() {
  cin >> n >> e;
  g.resize(e);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[i] = {u, v, w};
  }
  int source = 0;
  int destination = 6335;
  BellmanFord(source);
  Path(source, destination);
}