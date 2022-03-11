#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void level1(string &str) {
    for (char &i: str) {
        if (isupper(i)) i = tolower(i);
    }
}

void level2(string &str) {
    string temp;
    for (const char c: str) {
        if (isalpha(c)) {
            if (islower(c)) temp.push_back(c);
        } else if (isdigit(c)) {
            temp.push_back(c);
        } else {
            if (strchr("-_.", c)) temp.push_back(c);
        }
    }
    str = temp;
}

void level3(string &str) {
    string temp;
    for (char c: str) {
        if (!temp.empty() && temp.back() == '.' && c == '.') continue;
        temp.push_back(c);
    }
    str = temp;
}

void level4(string &str) {
    while (!str.empty() && (str.front() == '.' || str.back() == '.')) {
        if (!str.empty() && str.front() == '.') str.erase(str.begin());
        if (!str.empty() && str.back() == '.') str.pop_back();
    }
}

void level5(string &str) {
    if (str.empty()) str = "a";
}

void level6(string &str) {
    while (str.size() > 15) str.pop_back();
    level4(str);
}

void level7(string &str) {
    while (!str.empty() && str.size() < 3) {
        str += str.back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str = "...!@BaT#*..y.abcdefghijklm";
    //string str = "123_.def";
    //string str = "z-+.^.";
    cout << str << "\n";
    level1(str);
    cout << str << "\n";
    level2(str);
    cout << str << "\n";
    level3(str);
    cout << str << "\n";
    level4(str);
    cout << str << "\n";
    level5(str);
    cout << str << "\n";
    level6(str);
    cout << str << "\n";
    level7(str);
    cout << str << "\n";
    return 0;
}