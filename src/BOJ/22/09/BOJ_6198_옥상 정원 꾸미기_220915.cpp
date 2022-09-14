#include <iostream>
#include <vector>

using namespace std;

int N, input;
vector<int> temp;
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        while (!temp.empty() && temp.back() <= input) temp.pop_back();
        temp.push_back(input);
        answer += temp.size() - 1;
    }
    cout << answer << "\n";
    return 0;
}