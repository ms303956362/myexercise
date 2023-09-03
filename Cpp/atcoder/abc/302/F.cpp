// IO
#include <iostream>
#include <iomanip>      // std::setprecision
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> num2set(m), set2num(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int x;
            cin >> x;
            --x;
            set2num[i].push_back(x);
            num2set[x].push_back(i);
        }
    }
    vector<bool> vst_set(n), vst_num(m), is_ans(n);
    for (const auto& st : num2set[m - 1]) {
        is_ans[st] = true;
    }
    queue<int> q;
    vst_num[0] = true;
    for (const auto& s : num2set[0]) {
        q.push(s);
        vst_set[s] = true;
    }
    int step = 0;
    while (!q.empty()) {
        int l = q.size();
        while (l--) {
            int s = q.front();
            q.pop();
            if (is_ans[s]) {
                cout << step << '\n';
                return 0;
            }
            for (const auto& num : set2num[s]) {
                if (vst_num[num]) {
                    continue;
                }
                vst_num[num] = true;
                for (const auto& st : num2set[num]) {
                    if (vst_set[st]) {
                        continue;
                    }
                    vst_set[st] = true;
                    q.push(st);
                }
            }
        }
        ++step;
    }
    cout << -1 << '\n';
    return 0;
}
