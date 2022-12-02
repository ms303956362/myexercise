#include "usual.h"

// class BookMyShow {
//     using ll = long long;
//     ll sz;
//     ll n, m;
//     set<tuple<ll, ll, ll>> st;      // (len, row_id, seat_id)

// public:
//     BookMyShow(int _n, int _m): n(_n), m(_m), sz(n * (ll)m) {
//         for (int i = 0; i < n; ++i) {
//             st.emplace(m, i, i * m);
//         }
//     }
    
//     vector<int> gather(int k, int maxRow) {
//         vector<int> ans;
//         auto p = st.lower_bound(make_tuple(k, -1, -1));
//         if (p != st.end()) {
//             auto [num, row_id, seat_id] = *p;
//             if (row_id)
//             st.erase(p);
//             if (num - k > 0) {
//                 st.emplace(num - k, row_id, seat_id + k);
//             }
//             sz -= k;
//         }
//         return ans;
//     }
    
//     bool scatter(int k, int maxRow) {
//         if (sz < k) {
//             return false;
//         }

//     }
// };

class BookMyShow {
    using ll = long long;
    ll sz;
    int n, m;
    set<pair<int, int>> st;
    vector<set<pair<int, int>>::iterator> v;

public:
    BookMyShow(int _n, int _m): n(_n), m(_m), sz((ll)n * m) {
        for (int i = 0; i < n; ++i) {
            auto [p, ok] = st.emplace(i, m);
            v.push_back(p);
        }
    }
    
    vector<int> gather(int k, int maxRow) {
        auto p = st.lower_bound(make_pair(-1, k));
        if (p == st.end() || p->first > maxRow) {
            return {};
        }
        auto [row, len] = *p;
        st.erase(p);
        if (len > k) {
            auto [q, ok] = st.emplace(row, len - k);
            v[row] = q;
        } else {
            v[row] = st.end();
        }
        sz -= k;
        return {row, m - len};
    }
    
    bool scatter(int k, int maxRow) {
        long long sum = 0;
        bool ok = false;
        for (int i = 0; i <= maxRow; ++i) {
            if (v[i] == st.end()) {
                continue;
            }
            sum += (ll)v[i]->second;
            if (sum >= k) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
        for (int i = 0; i <= maxRow && k > 0; ++i) {
            if (v[i] == st.end()) {
                continue;
            }
            auto len = v[i]->second;
            if (k >= len) {
                k -= len;
            } else {
                st.erase(v[i]);
                auto [p, ok] = st.emplace(i, len - k);
                v[i] = p;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    BookMyShow bms = BookMyShow(2, 5); // 总共有 2 排，每排 5 个座位。
    bms.gather(4, 0); // 返回 [0, 0]
                    // 这一组安排第 0 排 [0, 3] 的座位。
    bms.gather(2, 0); // 返回 []
                    // 第 0 排只剩下 1 个座位。
                    // 所以无法安排 2 个连续座位。
    bms.scatter(5, 1); // 返回 True
                    // 这一组安排第 0 排第 4 个座位和第 1 排 [0, 3] 的座位。
    bms.scatter(5, 1); // 返回 False
                    // 总共只剩下 2 个座位。
    return 0;
}
