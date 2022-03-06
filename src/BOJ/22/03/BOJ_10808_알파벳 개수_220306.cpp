#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;
map<char, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    for (const char d: str) m[d]++;
    for (int i = 'a'; i <= 'z'; i++) cout << m[(char) i] << " ";
    cout << "\n";
    return 0;
}