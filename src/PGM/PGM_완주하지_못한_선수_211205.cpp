#include <iostream>=
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    vector<string> participant{"leo", "kiki", "eden"};
    vector<string> participant{"marina", "josipa", "nikola", "vinko", "filipa"};
//    vector<string> participant{"mislav", "stanko", "mislav", "ana"};
//    vector<string> completion{"eden", "kiki"};
    vector<string> completion{"josipa", "filipa", "marina", "nikola"};
//    vector<string> completion{"stanko", "ana", "mislav"};
    cout << solution(participant, completion) << "\n";
    return 0;
}