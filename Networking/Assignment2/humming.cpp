#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "This is (15, 11) Humming code" << endl;
    vector<bool> data(16, 0);
    string msg; 
    cout << "11-bit message : ";
    cin >> msg;
    for (int i = 15, j = 0; i > 2; i--) {
        if (i & (i - 1)) data[i] = msg[j++] == '1';
    }
    int code = 0;
    for (int i = 0; i < 16; i++) {
        if (data[i]) {
            code = code ^ i, data[0] = !data[0];
        }
    }
    data[1] = code & 1, data[2] = code & 2;
    data[4] = code & 4, data[8] = code & 8;
    cout << "Message sent : ";
    for (auto a : data) cout << a;
    cout << endl << "Creating error on 7th bit ... " << endl;
    cout << "Finding position of error ... " << endl;
    data[7] = !data[7];
    for (int i = 0; i < 16; i++) {
        if ((i & (i - 1)) && data[i]) code = code ^ i;
    }
    cout << "Error occured on position : " << code << endl;
}