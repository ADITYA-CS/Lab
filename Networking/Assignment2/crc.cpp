#include <bits/stdc++.h>
using namespace std;

string Fun(string data, string div) {
    int l1 = data.size(), l2 = div.size();
    for (int i = 0; i + l2 <= l1; i++) {
        if (data[i] != '1')
            continue;
        for (int j = 0; j < l2; j++) 
            data[i + j] = '0' + (data[i + j] + div[j]) % 2;
    }
    string res;
    for (int i = l1 - l2 + 1; i < l1; i++) 
        res += data[i];
    return res;
}
int main() {
    string data, div;
    cout << "Enter the data (in binary) : ";
    cin >> data;
    cout << "Enter the divisor (in binary) : ";
    cin >> div;
    string rem = Fun(data + string(div.size() - 1, '0'), div);
    cout << "Data + CRC : " << data + rem << endl;
    rem = Fun(data + rem, div);
    if (rem == string(div.size() - 1, '0')) {
        cout << "Correct data received\n";
    } else {
        cout << "some error occured.\n";
    }
}
