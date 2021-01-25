#include <iostream>
#include <string>
using namespace std;

int main() {
  int n; 
  cout << "No of frame : ";
  cin >> n;
  string tmp, msg;
  for (int i = 0; i < n; i++) {
    cout << "Frame " << i + 1 << " : ";
    cin >> tmp;
    msg += to_string(tmp.size());
    msg += tmp;
  }
  cout << "Message send to receiver : " << msg << endl;
  string res;
  int i = 0, c = 1, m = msg.size();
  while (i < m) {
    cout << "Frame " << c++ << " : ";
    for (int j = 1; j <= msg[i] - '0'; j++)
      cout << msg[i + j], res += msg[i + j];
    i += msg[i] - '0' + 1;
    cout << endl;
  }
  cout << "Message received by receiver : " << res;  
}
