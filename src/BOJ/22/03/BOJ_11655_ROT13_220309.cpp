#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> upperV, lowerV;

void init() {
    for (int i = 'A'; i <= 'Z'; i++) upperV.push_back((char) i);
    for (int i = 'a'; i <= 'z'; i++) lowerV.push_back((char) i);
}

char getChar(const char c, const vector<char> &v) {
    unsigned long currentPos = distance(v.begin(), find(v.begin(), v.end(), c));
    unsigned long targetPos = (currentPos + 13) % v.size();
    return v[targetPos];
}

char ROT13(const char c) {
    char result = c;
    if (isalpha(c)) {
        if (isupper(c)) {
            result = getChar(c, upperV);
        } else {
            result = getChar(c, lowerV);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    getline(cin, str);
    init();
    for (const char d: str) cout << ROT13(d);
    cout << "\n";
    return 0;
}