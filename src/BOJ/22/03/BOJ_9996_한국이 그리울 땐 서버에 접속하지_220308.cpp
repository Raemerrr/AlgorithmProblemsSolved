#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
string pattern;

bool solution(deque<char> &dq, deque<char> &str, bool isFront) {
    while (!dq.empty()) {
        if (str.empty()) {
            return false;
        }
        if (isFront) {
            if (dq.front() == str.front()) {
                dq.pop_front();
                str.pop_front();
            } else {
                return false;
            }
        } else {
            if (dq.back() == str.back()) {
                dq.pop_back();
                str.pop_back();
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> pattern;
    long pos = distance(pattern.begin(), find(pattern.begin(), pattern.end(), '*'));
    string prefix = pattern.substr(0, pos);
    string suffix = pattern.substr(pos + 1, pattern.size());
    while (N--) {
        string str;
        cin >> str;
        deque<char> prefixQ(prefix.begin(), prefix.end());
        deque<char> suffixQ(suffix.begin(), suffix.end());
        deque<char> strQ(str.begin(), str.end());
        if (!solution(prefixQ, strQ, true) || !solution(suffixQ, strQ, false)) {
            cout << "NE\n";
            continue;
        }
        cout << "DA\n";
    }
    return 0;
}