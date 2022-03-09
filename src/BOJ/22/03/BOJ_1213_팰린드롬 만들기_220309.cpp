#include <iostream>
#include <map>

using namespace std;

map<char, int> m;
string answer;

int checkOddNumberCount() {
    int result = 0;
    for (const pair<char, int> &d: m) {
        if (d.second % 2 != 0) result++;
    }
    return result;
}

void solution(const int oddNumberCnt) {
    // 조건 1 : 홀수 갯수를 가진게 없다면?
    // 현재 짝수 개의 알파벳을 절반만 가져온 후 가져온 알파벳을 뒤집어서 이어 붙인다.
    // ex) AABB 가 있다면 AB 가져온 후 BA를 이어 붙인다. -> ABBA
    if (oddNumberCnt == 0) {
        for (const pair<char, int> &d: m) {
            for (int i = 0; i < d.second / 2; i++) {
                answer += d.first;
            }
        }
        answer += string(answer.rbegin(), answer.rend());
    }
    // 조건 2 : 홀수 갯수를 가진게 한 개 있다면?
    // 현재 짝수 개의 알파벳을 절반만 가져오고,
    // 현재 홀수 개의 알파벳을 하나 뺀 절반만 가져오고,
    // 가져온 알파벳 + 홀수 개 알파벳 한개 + 가져온 알파벳을 뒤집어서 이어 붙인다.
    // ex) AAABB 가 있다면 AB 가져온 후 A 와 BA를 이어 붙인다. -> ABABA
    else if (oddNumberCnt == 1) {
        char oddChar = ' ';
        for (const pair<char, int> &d: m) {
            if (d.second % 2 == 0) {
                for (int i = 0; i < d.second / 2; i++) {
                    answer += d.first;
                }
            } else {
                for (int i = 0; i < (d.second - 1) / 2; i++) {
                    answer += d.first;
                }
                oddChar = d.first;
            }
        }
        answer += oddChar + string(answer.rbegin(), answer.rend());
    }
    // 조건 3 : 홀수 갯수를 가진게 여러개 있다면?
    // 팰린드롬을 만들수 없는 상황
    else {
        answer = "I'm Sorry Hansoo";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    for (const char d: str) m[d]++;
    solution(checkOddNumberCount());
    cout << answer << "\n";
    return 0;
}