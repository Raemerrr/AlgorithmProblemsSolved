#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string>> v;
vector<pair<int, int>> answer;

int timeToInt(string time) {
    int ss = stoi(time.substr(3, 2));
    int mm = stoi(time.substr(0, 2)) * 60;
    return mm + ss;
}

string intToTime(int time) {
    string ss = to_string(time % 60);
    if (ss.size() < 2) ss = "0" + ss;
    string mm = to_string(time / 60);
    if (mm.size() < 2) mm = "0" + mm;
    return mm + ":" + ss;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.assign(N, pair<int, string>());
    answer.assign(2, pair<int, int>());
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    v.emplace_back(0, "48:00");

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].first == 1) answer[0].first++;
        else answer[1].first++;
        int scoreA = answer[0].first;
        int scoreB = answer[1].first;
        if (scoreA != scoreB) {
            int add = timeToInt(v[i].second) - timeToInt(v[i - 1].second);
            ((scoreB < scoreA) ? answer[0].second += add : answer[1].second += add);
        }
    }
    cout << intToTime(answer[0].second) << "\n";
    cout << intToTime(answer[1].second) << "\n";
    return 0;
}