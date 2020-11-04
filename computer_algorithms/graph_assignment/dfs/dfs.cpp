#include <bits/stdc++.h>
using namespace std;


vector<list<int>> g;
int n;


void dfs(int u, vector<bool>  &visited) {
  visited[u] = true;

  for (auto v : g[u]) {
    if (visited[v] == false) {
      cout << "{" << u << " " << v << "}, ";
      dfs(v, visited);
    }
  }
}

void dfs() {
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      dfs(i, visited);
    }
  }
}

int main() {
  cin >> n;
  int e; cin >> e;
  g.resize(n);
  for (int i = 0; i < e; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << "Order in which edge is visited\n";
  dfs();
}