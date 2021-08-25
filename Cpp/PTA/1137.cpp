#include <string>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int p, m, n;
    cin >> p >> m >> n;
    map<int, set<string>> s;
    unordered_map<string, vector<int>> mp;
    string name;
    int score;
    for (int i = 0; i < p; ++i) {
        cin >> name >> score;
        if (mp.count(name) == 0)
            mp[name] = vector<int>(3, -1);
        mp[name][0] = score;
    }
    for (int i = 0; i < m; ++i) {
        string name;
        int score;
        cin >> name >> score;
        if (mp.count(name) == 0)
            mp[name] = vector<int>(3, -1);
        mp[name][1] = score;
    }
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        if (mp.count(name) == 0)
            mp[name] = vector<int>(3, -1);
        mp[name][2] = score;
    }
    for (const auto& [name, scores] : mp) {
        if (scores[0] >= 200) {
            int s1 = (scores[1] == -1 ? 0 : scores[1]), s2 = (scores[2] == -1 ? 0 : scores[2]);
            int final_score = (s1 > s2 ? (0.4 * s1 + 0.6 * s2 + 0.5) : s2);
            if (final_score >= 60)
                s[-final_score].insert(name);
        }
    }
    bool first = true;
    for (const auto& [final_score, ss] : s) {
        for (const auto& name : ss) {
            if (!first) {
                cout << endl;
            } else {
                first = false;
            }
            cout << name << " " << mp[name][0] << " " << mp[name][1] << " " << mp[name][2] << " " << -final_score;
        }
    }
    return 0;
}
