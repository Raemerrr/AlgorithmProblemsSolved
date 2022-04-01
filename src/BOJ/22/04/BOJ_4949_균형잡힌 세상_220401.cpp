#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (true) {
        getline(cin, str);
        if (str == ".") break;
        vector<char> v;
        bool flag = true;
        for (const char c: str) {
            if (c == '(' || c == '[') {
                v.push_back(c);
            } else if (c == ')' || c == ']') {
                if (v.empty() || (c == ')' && v.back() != '(') || (c == ']' && v.back() != '[')) {
                    flag = false;
                    break;
                }
                v.pop_back();
            }
        }
        cout << (flag && v.empty() ? "yes" : "no") << "\n";
    }
    return 0;
}