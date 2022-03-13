#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int parse(const string &time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return (hh * 60) + mm;
}

int calculate(const vector<int> &fees, const int hoursOfUse) {
    int result = fees[1];
    if (fees[0] < hoursOfUse) {
        int price = (int) ceil((hoursOfUse - fees[0]) / (double) fees[2]);
        result += price * fees[3];
    }
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, queue<pair<int, string>>> order;
    map<string, int> hoursOfUse;
    for (const string &record: records) {
        stringstream in(record);
        string a, b, c;
        in >> a >> b >> c;
        order[b].emplace(parse(a), c);
    }

    for (pair<string, queue<pair<int, string>>> d: order) {
        while (!d.second.empty()) {
            pair<int, string> in = d.second.front();
            d.second.pop();
            pair<int, string> out = pair<int, string>({parse("23:59"), "OUT"});
            if (!d.second.empty() && d.second.front().second == "OUT") {
                out = d.second.front();
                d.second.pop();
            }
            hoursOfUse[d.first] += out.first - in.first;
        }
    }

    for (const pair<string, int> &h: hoursOfUse) {
        answer.push_back(calculate(fees, h.second));
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> fees{180, 5000, 10, 600};
    vector<string> records{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN",
                           "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    for (const int d: solution(fees, records)) {
        cout << d << " ";
    }
    cout << "\n";
    return 0;
}