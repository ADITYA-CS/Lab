#include <bits/stdc++.h>
using namespace std;

double Fibo(int p) {
  if (p ==0)
    return 1;
  
  double t = Fibo(p / 2);
  t *= t;
  if (p & 1) {
    return t * (1 + sqrt(5)) / 2.0;
  }
  return t;
}

int main() {
  int n; cin >> n;
  double res = Fibo(n);
  res /= sqrt(5);
  cout << (long long)round(res) << endl;
}