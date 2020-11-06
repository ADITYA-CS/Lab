#include <bits/stdc++.h>
using namespace std;

void DFS1(int u, const vector<list<int>> &g, vector<bool> &visited,
          stack<int> &topological_order) {
  visited[u] = true;
  for (auto v : g[u]) {
    if (visited[v] == false) {
      DFS1(v, g, visited, topological_order);
    }
  }
  topological_order.push(u);
}

void DFS2(int u, const vector<list<int>> &g, vector<bool> &visited,
          stack<int> &component) {
  visited[u] = true;
  component.push(u);
  for (auto v : g[u]) {
    if (visited[v] == false) {
      DFS2(v, g, visited, component);
    }
  }
}

void Kosaraju(const vector<list<int>> &g, const vector<list<int>> &gr,
              const int n) {
  vector<bool> visited(n, false);
  stack<int> topological_order;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      DFS1(i, g, visited, topological_order);
    }
  }
  visited.assign(n, false);
  stack<int> component;
  int connected_componet = 0;
  while (topological_order.size()) {
    int u = topological_order.top();
    topological_order.pop();
    if (visited[u] == false) {
      DFS2(u, gr, visited, component);
      connected_componet++;
      cout << "Connected Component " << connected_componet << " : {";
      while (component.size() > 1) {
        cout << component.top() << ", ";
        component.pop();
      }
      cout << component.top() << "}\n";
      component.pop();
    }
  }
}

int main() {
  vector<list<int>> g, gr;
  int n, e;
  cin >> n >> e;
  g.resize(n), gr.resize(n);
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    gr[v].push_back(u);
  }
  Kosaraju(g, gr, n);
}