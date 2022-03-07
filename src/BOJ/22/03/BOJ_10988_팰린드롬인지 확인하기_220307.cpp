#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

deque<char> dq;
string str;
bool answer = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    for (const char d: str) dq.push_back(d);
    while (!dq.empty()) {
        char f = dq.front();
        dq.pop_front();
        if (dq.empty()) break;
        char b = dq.back();
        dq.pop_back();
        if (f != b) {
            answer = false;
            break;
        }
    }
    cout << (answer ? '1' : '0') << "\n";
    return 0;
}