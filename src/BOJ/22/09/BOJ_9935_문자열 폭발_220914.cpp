#include <iostream>
#include <string>

using namespace std;

string input, target, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> input >> target;
    for (const char c: input) {
        answer += c;
        if (target.size() <= answer.size()
            && answer.back() == target.back()
            && answer.substr(answer.size() - target.size(), target.size()) == target) {
            answer.erase(answer.size() - target.size(), target.size());
        }
    }
    cout << (answer.empty() ? "FRULA" : answer) << "\n";
    return 0;
}