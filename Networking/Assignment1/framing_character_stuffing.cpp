#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string msg, res = "dlestx";
  cout << "Enter Message : ";
  getline(cin, msg);
  int pos, n = msg.size();
  char ch;
  cout << "Enter position : ";
  cin >> pos;
  cout << "Enter character : ";
  cin >> ch;
  for (int i = 0; i < n; i++) {
    if (i == pos - 1) {
      res += "dle";
      res += ch;
      res += "dle";
    }
    if (i + 2 < n && msg[i] == 'd' && msg[i + 1] == 'l' && msg[i + 2] == 'e') {
      res += "dle";
    }
    res += msg[i];
  }
  res += "dleetx";
  cout << "Final frame : " << res;
}
