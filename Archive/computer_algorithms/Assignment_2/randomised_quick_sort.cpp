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

void QuickSort(vector<int>& v, int l, int r) {
  if (l >= r) return;
  int m = RandomisedSelect(v, l, r);
  QuickSort(v, l, m - 1);
  QuickSort(v, m + 1, r);
}


int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (auto &e : v)
    cin >> e;
  QuickSort(v, 0, v.size() - 1);
  for (auto &e : v)
    cout << e << " ";
  cout << endl;
}