#include <bits/stdc++.h>
using namespace std;

struct edge{
  int u, v, e;
  friend ostream& operator<<(ostream& out, edge& e) {
    out << e.u << " " << e.v << "\n"; // << e.e << "\n";
    return out;
  }
};

int main() {
  int n = 1000;
  random_device random_device;
  mt19937 random_engine(random_device());
  uniform_int_distribution<int> dist(0, n - 1);
  
  // while (n < 50000) {
  //   n = rand() % 100000;
  // }
  int e = n * 5;
  std::cout << n << " " << e << endl;

  vector<edge> v;
  // for (int i = 1; i  < n; i++) {
  //   v[i] = {i, i - 1, rand() % 50 + 1};
  // }
  for (int i = 0; i < e; i++) {
    int a = dist(random_engine);
    int b = a;
    while (b == a) {
      b = dist(random_engine);
    }
    v.push_back({a, b, dist(random_engine)});
  }
  std::shuffle(v.begin(), v.end(), default_random_engine(0));
  for (auto r : v) {
    std::cout << r;
  }
  // for (int i = 0; i < n / 2; i++) {
  //   cout << i << " " << (n / 2 + i) << endl;
  // }
}