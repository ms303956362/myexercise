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
#include <numeric>
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
    vector<string> grid(50, string(50, '.'));
    int ha, wa;
    cin >> ha >> wa;
    vector<string> grida(ha, string(wa, '.'));
    for (int i = 0; i < ha; ++i) {
        for (int j = 0; j < wa; ++j) {
            cin >> grida[i][j];
        }
    }
    int hb, wb;
    cin >> hb >> wb;
    vector<string> gridb(hb, string(wb, '.'));
    for (int i = 0; i < hb; ++i) {
        for (int j = 0; j < wb; ++j) {
            cin >> gridb[i][j];
        }
    }
    int hx, wx;
    cin >> hx >> wx;
    vector<string> gridx(hx, string(wx, '.'));
    for (int i = 0; i < hx; ++i) {
        for (int j = 0; j < wx; ++j) {
            cin >> gridx[i][j];
        }
    }
    int ia1 = 50, ja1 = 50, ia2 = 0, ja2 = 0;
    for (int i = 20; i < 20 + ha; ++i) {
        for (int j = 20; j < 20 + wa; ++j) {
            grid[i][j] = grida[i - 20][j - 20];
            if (grid[i][j] == '#') {
                ia1 = min(ia1, i);
                ia2 = max(ia2, i);
                ja1 = min(ja1, j);
                ja2 = max(ja2, j);
            }
        }
    }
    int ix1 = 50, jx1 = 50, ix2 = 0, jx2 = 0;
    for (int i = 0; i < hx; ++i) {
        for (int j = 0; j < wx; ++j) {
            if (gridx[i][j] == '#') {
                ix1 = min(ix1, i);
                ix2 = max(ix2, i);
                jx1 = min(jx1, j);
                jx2 = max(jx2, j);
            }
        }
    }
    auto check = [&](vector<string>& g, int ix1, int jx1, int ix2, int jx2, int ic1, int jc1, int ic2, int jc2) {
        if (ix2 - ix1 != ic2 - ic1 || jx2 - jx1 != jc2 - jc1) {
            return false;
        }
        int h = ix2 - ix1 + 1, w = jx2 - jx1 + 1;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (gridx[ix1 + i][jx1 + j] != g[ic1 + i][jc1 + j]) {
                    return false;
                }
            }
        }
        return true;
    };
    bool ok = false;
    for (int i = 0; i < 50 - hb; ++i) {
        for (int j = 0; j < 50 - wb; ++j) {
            vector<string> g(grid);
            int ic1 = ia1, jc1 = ja1, ic2 = ia2, jc2 = ja2;
            for (int h = 0; h < hb; ++h) {
                for (int w = 0; w < wb; ++w) {
                    if (gridb[h][w] == '#') {
                        g[i + h][j + w] = '#';
                        ic1 = min(ic1, i + h);
                        ic2 = max(ic2, i + h);
                        jc1 = min(jc1, j + w);
                        jc2 = max(jc2, j + w);
                    }
                }
            }
            if (check(g, ix1, jx1, ix2, jx2, ic1, jc1, ic2, jc2)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}
