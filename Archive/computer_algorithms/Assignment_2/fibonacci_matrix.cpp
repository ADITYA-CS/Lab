#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > Mulitply(vector<vector<long long> > &a, 
    vector<vector<long long> >& b) {
  vector<vector<long long> > tmp{{0,0}, {0,0}};
  int n = a.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        tmp[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return tmp;
}

vector<vector<long long> > MatrixPower(vector<vector<long long> > &v, int p) {
  if (p == 0) {
    return move(vector<vector<long long> >{{1,0},{0,1}});
  }
  auto tmp = MatrixPower(v, p / 2);
  tmp = Mulitply(tmp, tmp);
  if (p & 1) {
    return move(Mulitply(tmp, v));
  } 
  return tmp;
}

int main() {
  
  long long n; cin >> n;
  vector<vector<long long> > v{{1,1},{1,0}};
  auto m = Mulitply(v, v);
  v = MatrixPower(v, n);  
  cout << v[0][1] << "\n";
}