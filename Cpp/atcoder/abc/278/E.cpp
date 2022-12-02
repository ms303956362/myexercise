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
    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;
    vector<vector<int>> a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<vector<int>>> cnt(H + 1, vector<vector<int>>(W + 1, vector<int>(n + 1)));
    for (int i = H - 1; i >= 0; --i) {
        for (int j = W - 1; j >= 0; --j) {
            for (int k = 0; k <= n; ++k) {
                cnt[i][j][k] = (a[i][j] == k) + cnt[i + 1][j][k] + cnt[i][j + 1][k] - cnt[i + 1][j + 1][k];
            }
        }
    }
    for (int i = 0; i <= H - h; ++i) {
        for (int j = 0; j <= W - w; ++j) {
            int diff = 0;
            for (int k = 0; k <= n; ++k) {
                int cnt_local = cnt[i][j][k] - cnt[i][j + w][k] - cnt[i + h][j][k] + cnt[i + h][j + w][k];
                if (cnt_local < cnt[0][0][k]) {
                    ++diff;
                }
            }
            cout << diff << " ";
        }
        cout << endl;
    }
    return 0;
}
