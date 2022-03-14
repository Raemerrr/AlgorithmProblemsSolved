#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string pattern, prefix, suffix;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> pattern;
    unsigned long asteriskPos = pattern.find('*');
    prefix = pattern.substr(0, asteriskPos);
    suffix = pattern.substr(asteriskPos + 1, pattern.size());
    int minimumSize = prefix.size() + suffix.size();
    while (N--) {
        string str;
        cin >> str;
        if (str.size() < minimumSize) {
            cout << "NE\n";
            continue;
        }
        if (prefix == str.substr(0, prefix.size()) &&
            suffix == str.substr(str.size() - suffix.size(), str.size())) {
            cout << "DA\n";
            continue;
        }
        cout << "NE\n";
    }
    return 0;
}