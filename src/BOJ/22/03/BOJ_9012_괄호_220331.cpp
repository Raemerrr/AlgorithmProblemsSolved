#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        vector<char> v;
        bool answer = true;
        string str;
        cin >> str;
        for (const char c: str) {
            if (c == '(') v.push_back(c);
            else {
                if (v.empty()) {
                    answer = false;
                    break;
                }
                v.pop_back();
            }
        }
        cout << (answer && v.empty() ? "YES" : "NO") << "\n";
    }
    return 0;
}