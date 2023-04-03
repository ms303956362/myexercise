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

class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode(): children(11) {}
};

void solve() {
    int n, m;
    cin >> n >> m;
    TrieNode *root = new TrieNode();
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> idx(m + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            idx[a[i][j]] = j + 1;
        }
        TrieNode *p = root;
        for (int j = 1; j <= m; ++j) {
            if (!p->children[idx[j]]) {
                p->children[idx[j]] = new TrieNode();
            }
            p = p->children[idx[j]];
        }
    }
    for (int i = 0; i < n; ++i) {
        TrieNode* p = root;
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            if (!p->children[a[i][j]]) {
                break;
            }
            p = p->children[a[i][j]];
            ++ans;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
