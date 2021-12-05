#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str, pattern, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str >> pattern;
    for (int i = 0; i < str.size(); i++) {
        answer.push_back(str[i]);
        if (pattern.back() == str[i] && answer.size() >= pattern.size() &&
            answer.substr(answer.size() - pattern.size(), pattern.size()) == pattern) {
            for (int j = 0; j < pattern.size(); j++) {
                answer.pop_back();
            }
        }
    }
    cout << ((!answer.empty()) ? answer : "FRULA") << "\n";
    return 0;
}