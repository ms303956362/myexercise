#include "usual.h"

int solve1(vector<pair<int, int>>& points) {
    int n = points.size();
    map<pair<int, int>, map<pair<int, int>, int>> cnt;
    for (int i = 0; i < n; ++i) {
        int x0 = points[i].first, y0 = points[i].second;
        for (int j = i + 1; j < n; ++j) {
            int dx = x0 - points[j].first, dy = y0 - points[j].second;
            if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            } else {
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
            }
            ++cnt[make_pair(x0, y0)][make_pair(dx, dy)];
        }
    }
    int ans = 0;
    for (const auto& [p, km] : cnt) {
        for (const auto& [k, c] : km) {
            ans += c * (c - 1) / 2;
        }
    }
    return ans;
}

int solve2(vector<pair<int, int>>& points) {
    int n = points.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
        int x0 = points[i].first, y0 = points[i].second;
        for (int j = i + 1; j < n; ++j) {
            int x1 = points[j].first, y1 = points[j].second;
            for (int k = j + 1; k < n; ++k) {
                int x2 = points[k].first, y2 = points[k].second;
                if ((x1 - x0) * (y2 - y0) == (x2 - x0) * (y1 - y0)) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

void print(vector<pair<int, int>>& v) {
    for (const auto& p : v) {
        cout << p.first << " " << p.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    int total = 100, t = total;
    int correct = 0;
    while (t--) {
        int n = rand() % 998 + 3;   // 3 <= n && n <= 1000
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            int x = rand() % 1000, y = rand() % 1000;
            s.emplace(x, y);
        }
        vector<pair<int, int>> v(s.begin(), s.end());
        int ans1 = solve1(v), ans2 = solve2(v);
        cout << "Input: " << endl;
        cout << v.size() << endl;
        print(v);
        cout << "Expected: " << ans2 << endl;
        cout << "Output: " << ans1 << endl;
        if (ans1 == ans2) {
            cout << "Accepted" << endl;
            ++correct;
        } else {
            cout << "Wrong answer" << endl;
        }
    }
    cout << "total: " << total << ", correct: " << correct << endl;
    if (total == correct) {
        cout << "Accepted" << endl;
    }
    return 0;
}


// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> points;
//     for (int i = 0; i < n; ++i) {
//         int x, y;
//         cin >> x >> y;
//         points.emplace_back(x, y);
//     }
//     map<pair<int, int>, map<pair<int, int>, int>> cnt;
//     for (int i = 0; i < n; ++i) {
//         int x0 = points[i].first, y0 = points[i].second;
//         for (int j = i + 1; j < n; ++j) {
//             int dx = x0 - points[j].first, dy = y0 - points[j].second;
//             if (dx == 0) {
//                 dy = 1;
//             } else if (dy == 0) {
//                 dx = 1;
//             } else {
//                 if (dx < 0) {
//                     dx = -dx;
//                     dy = -dy;
//                 }
//                 int g = __gcd(abs(dx), abs(dy));
//                 dx /= g;
//                 dy /= g;
//             }
//             ++cnt[make_pair(x0, y0)][make_pair(dx, dy)];
//         }
//     }
//     int ans = 0;
//     for (const auto& [p, km] : cnt) {
//         for (const auto& [k, c] : km) {
//             ans += c * (c - 1) / 2;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
