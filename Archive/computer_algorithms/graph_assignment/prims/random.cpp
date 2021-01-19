#include <bits/stdc++.h>
using namespace std;

struct edge{
  int u, v, e;
  friend ostream& operator<<(ostream& out, edge& e) {
    out << e.u << " " << e.v << " " << e.e << "\n";
    return out;
  }
};

int main() {
  int n = 0;
  while (n < 50000) {
    n = rand() % 100000;
  }
  cout << n << endl;

  vector<edge> v(n);
  for (int i = 1; i  < n; i++) {
    v[i] = {i, i - 1, rand() % 50 + 1};
  }
  int e = n * 1.2;
  for (int i = n; i < e; i++) {
    int a = rand() % n;
    int b = a;
    while (b == a) {
      b = rand() % n;
    }
    v.push_back({a, b, rand() % 50 + 1});
  }
  cout << e << endl;
  shuffle(v.begin(), v.end(), default_random_engine(0));
  for (auto r : v) {
    cout << r;
  }
}