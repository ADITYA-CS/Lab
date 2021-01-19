#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <list>
using namespace std;

struct Edge {
  int v, w;
};

vector<list<Edge>> g;
int n;
vector<int> key, parent;
vector<bool> in_mst;

void Prim(int source = 0) {
  key.resize(n, INT_MAX);
  parent.resize(n, -1);
  in_mst.resize(n, false);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, source});
  while (pq.size()) {
    auto u = pq.top().second;
    pq.pop();
    in_mst[u] = true;
    for (auto e : g[u]) {
      if (in_mst[e.v] == false && key[e.v] > e.w) {
        key[e.v] = e.w;
        pq.push({key[e.v], e.v});
        parent[e.v] = u;
      }
    }
  }
}
bool FoundMst() {
  bool found = true;
  for (int i = 0; i < n; i++)
    found &= in_mst[i];
  return found;
}

void PrintMst() {
  int flag = 1;
  int b = 1000;
  for (int i = 1; i < n; i++) {
    if (flag)
      printf(", ");
    printf("{%5d, %5d}", parent[i], i);
    flag = (flag + 1) % 5;
    if (!flag)
      printf("\n");
    b--;
    if(!b)
      break;
  }
}

int main() {
  cin >> n;
  g.resize(n);
  int m, u, v, w;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  Prim();
  if (FoundMst()){
    cout << "Edge of MST: ";
    PrintMst();
  } else {
    printf("No MST possible\n");
  }
}