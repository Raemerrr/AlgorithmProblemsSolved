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
    while (N--) {
        string str;
        cin >> str;
        if (str.size() < prefix.size() + suffix.size()) {
            cout << "NE" << "\n";
        } else {
            if (str.substr(0, prefix.size()) == prefix &&
                str.substr(str.size() - suffix.size(), suffix.size()) == suffix) {
                cout << "DA" << "\n";
            } else {
                cout << "NE" << "\n";
            }
        }
    }
    return 0;
}