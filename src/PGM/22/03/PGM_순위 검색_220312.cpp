#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

enum language {
    cpp, java, python, langAll
};
enum tech {
    backend, frontend, techAll
};
enum career {
    junior, senior, careerAll
};
enum food {
    chicken, pizza, foodAll
};

const int languageSize = 3;
const int techSize = 2;
const int careerSize = 2;
const int foodSize = 2;

vector<int> v[languageSize][techSize][careerSize][foodSize];

language getLanguage(const string &str) {
    if (str == "cpp") return cpp;
    else if (str == "java") return java;
    else if (str == "python") return python;
    else return langAll;
}

tech getTech(const string &str) {
    if (str == "backend") return backend;
    else if (str == "frontend") return frontend;
    else return techAll;
}

career getCareer(const string &str) {
    if (str == "junior") return junior;
    else if (str == "senior") return senior;
    else return careerAll;
}

food getFood(const string &str) {
    if (str == "chicken") return chicken;
    else if (str == "pizza") return pizza;
    else return foodAll;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (const string &d: info) {
        vector<string> arr;
        istringstream is(d);
        string buffer;
        while (getline(is, buffer, ' ')) {
            arr.emplace_back(buffer);
        }
        int languageFlag = getLanguage(arr[0]);
        int techFlag = getTech(arr[1]);
        int careerFlag = getCareer(arr[2]);
        int foodFlag = getFood(arr[3]);
        v[languageFlag][techFlag][careerFlag][foodFlag].push_back(stoi(arr[4]));
    }

    for (int i = 0; i < languageSize; i++) {
        for (int j = 0; j < techSize; j++) {
            for (int k = 0; k < foodSize; k++) {
                for (int l = 0; l < careerSize; l++) {
                    sort(v[i][j][k][l].begin(), v[i][j][k][l].end());
                }
            }
        }
    }

    for (const string &d: query) {
        int cnt = 0;

        vector<string> arr;
        istringstream is(d);
        string buffer;
        while (getline(is, buffer, ' ')) {
            arr.push_back(buffer);
        }
        int languageFlag = getLanguage(arr[0]);
        int techFlag = getTech(arr[2]);
        int careerFlag = getCareer(arr[4]);
        int foodFlag = getFood(arr[6]);
        int score = stoi(arr[7]);

        for (int i = (languageFlag == langAll ? 0 : languageFlag); i < (languageFlag == langAll ? languageSize : languageFlag + 1); i++) {
            for (int j = (techFlag == techAll ? 0 : techFlag); j < (techFlag == techAll ? techSize : techFlag + 1); j++) {
                for (int k = (careerFlag == careerAll ? 0 : careerFlag); k < (careerFlag == careerAll ? careerSize : careerFlag + 1); k++) {
                    for (int l = (foodFlag == foodAll ? 0 : foodFlag); l < (foodFlag == foodAll ? foodSize : foodFlag + 1); l++) {
                        cnt += v[i][j][k][l].end() - lower_bound(v[i][j][k][l].begin(), v[i][j][k][l].end(), score);
                    }
                }

            }
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> info{"java backend junior pizza 150", "python frontend senior chicken 210",
                        "python frontend senior chicken 150", "cpp backend senior pizza 260",
                        "java backend junior chicken 80", "python backend senior chicken 50"};
    vector<string> query{"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
                         "cpp and - and senior and pizza 250", "- and backend and senior and - 150",
                         "- and - and - and chicken 100", "- and - and - and - 150"};
    for (const int d: solution(info, query)) {
        cout << d << "\n";
    }
    return 0;
}