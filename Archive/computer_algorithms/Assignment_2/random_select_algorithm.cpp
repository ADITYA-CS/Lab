#include <iostream>
#include <vector>
#include <random>
using namespace std;


int Partition(vector<int>& v, int l, int r){
  int pivot = v[r];
  int i = l;
  for (int j = l; j < r; j++) {
    if (v[j] <= pivot) {
      swap(v[i++], v[j]);
    }
  }
  swap(v[r], v[i]);
  return i;
}

int RandomisedSelect(vector<int>& v, int l, int r) {
  random_device random_device;
  mt19937 random_engine(random_device());
  uniform_int_distribution<int> dist(l, r);
  int i = dist(random_engine);
  swap(v[r], v[i]);
  return Partition(v, l, r);
}

int Select(vector<int>& v, int l, int r, int i) {
  if (l >= r) 
    return v[l];
  int m = RandomisedSelect(v, l, r);
  int k = m - l + 1;
  if (i == k)
    return v[m];
  else if (i < k)
    return Select(v, l, m - 1, i);
  return Select(v, m + 1, r, i - k);
}


int main() {
  int n = 100;
  vector<int> v(n);
  for (auto &e : v)
    e = n--;
  cout << Select(v, 0, v.size() - 1, 100) << endl;
  cout << Select(v, 0, v.size() - 1, 1) << endl;
}