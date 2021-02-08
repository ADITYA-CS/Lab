#include <bits/stdc++.h>
using namespace std;

int main() {
    string msg;
    cout << "Message (in binary) : ";
    cin >> msg;
    int one = 0;
    for (auto ch : msg) {
        one = (one + (ch - '0')) & 1;
    }
    string odd_parity_message = msg + (char)('0' + !one);
    string even_parity_message = msg + (char)('0' + one);
    cout << "Even parity\n";
    cout << "\tMessage sent : " << even_parity_message << endl;
    cout << "Odd parity\n";
    cout << "\tMessage sent : " << odd_parity_message << endl;
}