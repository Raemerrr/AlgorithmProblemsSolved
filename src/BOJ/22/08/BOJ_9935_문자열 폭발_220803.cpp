#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str, pattern, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str >> pattern;
    for (const char c: str) {
        answer.push_back(c);
        while (answer.size() >= pattern.size() && answer.back() == pattern.back()
            && answer.substr(answer.size() - pattern.size(), pattern.size()) == pattern) {
            for (int i = 0; i < pattern.size(); i++) {
                answer.pop_back();
            }
        }
    }
    cout << (answer.empty() ? "FRULA" : answer) << "\n";
    return 0;
}