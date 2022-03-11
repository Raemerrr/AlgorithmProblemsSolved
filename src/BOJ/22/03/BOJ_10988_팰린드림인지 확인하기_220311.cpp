#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    cout << (str == temp ? "1" : "0") << "\n";
    return 0;
}