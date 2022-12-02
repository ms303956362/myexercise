#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int pre[13];

int date2stamp(const string& s) {
    int month = stoi(s.substr(5, 2)), day = stoi(s.substr(8, 2));
    return pre[month - 1] + day;
}

int main(int argc, char const *argv[])
{
    pre[0] = 0;
    for (int i = 1; i <= 12; ++i) {
        pre[i] = pre[i - 1] + days[i];
    }
    int k;
    cin >> k;
    vector<pair<int, string>> logs;
    while (k--) {
        string name, date;
        cin >> name >> date;
        // int i = 0, m = log.size();
        // while (i < m && log[i] != ' ') {
        //     ++i;
        // }
        logs.emplace_back(date2stamp(date), name);
    }
    int l;
    cin >> l;
    sort(logs.begin(), logs.end());
    int n = logs.size();
    int i = 0, j = 0, ans = 0x3f3f3f3f;
    unordered_map<string, int> cnt;
    while (i < n) {
        j = max(j, i);
        while (j < n && cnt.size() < l) {
            ++cnt[logs[j].second];
            if (cnt.size() >= l) {
                break;
            }
            ++j;
        }
        if (j < n && cnt.size() >= l) {
            ans = min(ans, logs[j].first - logs[i].first + 1);
        }
        --cnt[logs[i].second];
        if (cnt[logs[i].second] == 0) {
            cnt.erase(logs[i].second);
        }
        ++i;
    }
    cout << (ans >= 0x3f3f3f3f ? -1 : ans) << endl;
    return 0;
}
