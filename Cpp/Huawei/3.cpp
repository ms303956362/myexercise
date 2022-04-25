#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <cstdio>
using namespace std;


int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int m, n, x;
    cin >> m >> n >> x;
    unordered_map<string, vector<int>> boss, cand;
    vector<vector<string>> bl(m), cl(n);
    char ccc;
    scanf("%c", &ccc);
    for (int i = 0; i < m; ++i) {
        string s;
        char c = '0';
        while (c != '\n') {
            scanf("%c", &c);
            s.push_back(c);
        }
        s.pop_back();
        int len = s.size();
        int j = 0;
        while (j < len) {
            int k = j + 1;
            while (k < len && s[k] != ' ') {
                ++k;
            }
            string t(s.substr(j, k - j));
            bl[i].push_back(t);
            boss[t].push_back(i);
            j = k + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        string s;
        char c = '0';
        while (c != '\n') {
            scanf("%c", &c);
            s.push_back(c);
        }
        s.pop_back();
        int len = s.size();
        int j = 0;
        while (j < len) {
            int k = j + 1;
            while (k < len && s[k] != ' ') {
                ++k;
            }
            string t(s.substr(j, k - j));
            cl[i].push_back(t);
            cand[t].push_back(i);
            j = k + 1;
        }
    }
    vector<vector<int>> g(m);
    for (int i = 0; i < m; ++i) {
        for (const auto& l : bl[i]) {
            for (const auto& j : cand[l]) {
                g[i].push_back(j);
            }
        }
    }
    vector<vector<int>> mian(n, vector<int>(2, -1));   
    function<bool(int)> backtrack = [&](int i) {
        if (i == m) {
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (mian[i][0] == -1 || mian[i][1] == -1) {
                    ok = false;
                    break;
                }
            }
            return ok;
        }
        function<bool(int)> cmk = [&](int cnt) {
            if (cnt == 0) {
                return backtrack(i + 1);
            }
            for (const auto& j : g[i]) {
                if (mian[j][0] == -1) {
                    mian[j][0] = i;
                    if (cmk(cnt - 1)) {
                        return true;
                    }
                    mian[j][0] = -1;
                } else if (mian[j][1] == -1) {
                    mian[j][1] = i;
                    if (cmk(cnt - 1)) {
                        return true;
                    }
                    mian[j][1] = -1;
                }
            }
            return backtrack(i + 1);
        };
        return cmk(min((int)g[i].size(), x));
    };
    auto ok = backtrack(0);
    if (!ok) {
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
        vector<vector<int>> match(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            match[mian[i][0]][i] = 1;
            match[mian[i][1]][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << match[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
