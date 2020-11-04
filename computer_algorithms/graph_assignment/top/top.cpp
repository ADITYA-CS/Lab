#include <bits/stdc++.h>
using namespace std;

vector<list<int>> g;
int n;

void TopologicalSort(int u, vector<bool> &visited, stack<int>& order) {
  visited[u] = true;
  for (auto v : g[u]) {
    if (visited[v]) {
      cout << "Graph contain a cycle\n";
      exit(1);
    } else {
      TopologicalSort(v, visited, order);
    }
  }
  order.push(u);
}

void Print(vector<int> &v) {
  for (int i :v) {
    if(i == -1)
      cout << "\n";
    else 
      cout << i << " ";
  }
}

void TopologicalSort() {
  vector<bool> visited(n, false);
  stack<int> order;
  vector<int> topological_sorted_item;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      TopologicalSort(i, visited, order);
      while (order.size()) {
        topological_sorted_item.push_back(order.top());
        order.pop();
      }
      topological_sorted_item.push_back(-1);
    }
  }
  Print(topological_sorted_item);
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
  TopologicalSort();
}