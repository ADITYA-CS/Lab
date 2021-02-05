#include <vector>
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter no of bits : ";
  cin >> n;
  vector<int> frame;
  int c = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t) c++;
    else c = 0;
    frame.push_back(t);
    if (c == 5) 
      frame.push_back(0), c = 0;
  }
  cout << "Data after stuffing : ";
  for (auto e : frame)
      cout << e;
}
