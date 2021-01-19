#include <bits/stdc++.h>
using namespace std;

vector<list<int>> g;
int n;

void bfs(int source, vector<bool> &visited) {
  visited[source] = true;
  int distance = 0;
  queue<int> q;
  q.push(source);
  while (q.size()) {
    int size = q.size();
    distance++;
    while (size--) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (visited[v] == false) {
          cout << "{" << u << ", " << v << "}, ";
          visited[v] = true;
          q.push(v);
        }
      }
    }
    cout << endl << endl;
  }
}

void bfs() {
  cout << "Order in which edge is visited\n";
  vector<bool> visited(n, false);
  bfs(0, visited);
  // for (int i = 0; i < n; i++) {
  //   if (visited[i] == false) {
  //     if (g[i].size()) 
  //       bfs(i, visited);
  //   }
  // }
}

int main() {
  cin >> n;
  g.resize(n);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs();
}