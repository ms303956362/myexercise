#include "usual.h"

// class CountIntervals {
//     int cnt;
//     set<pair<int, int>> st;

// public:
//     CountIntervals(): cnt(0) {

//     }
    
//     void add(int left, int right) {
//         auto p = st.lower_bound(make_pair(left, right));
//         if (p != st.begin()) {
//             p = prev(p);
//         }
//         if (p != st.end() && p->first <= left && right <= p->second) {
//             return;
//         }
//         int l = left, r = right;
//         while (p != st.end() && p->first <= right + 1) {
//             auto q = next(p);
//             if ((left <= p->first && p->first <= right + 1) || (left - 1 <= p->second && p->second <= right)) {
//                 l = min(l, p->first);
//                 r = max(r, p->second);
//                 cnt -= p->second - p->first + 1;
//                 st.erase(p);
//             }
//             p = q;
//         }
//         st.emplace(l, r);
//         cnt += r - l + 1;
//     }
    
//     int count() {
//         return cnt;
//     }
// };

class CountIntervals {
    int cnt;
    set<pair<int, int>> st;

public:
    CountIntervals(): cnt(0) {

    }
    
    void add(int left, int right) {
        auto p = st.lower_bound(make_pair(left, right));
        if (p != st.begin()) {
            p = prev(p);
        }
        if (p != st.end() && p->first <= left && right <= p->second) {
            return;
        }
        int l = left, r = right;
        while (p != st.end() && p->first <= right) {
            auto q = next(p);
            if (left <= p->first && p->first <= right || left <= p->second && p->second <= right) {
                l = min(l, p->first);
                r = max(r, p->second);
                cnt -= p->second - p->first + 1;
                st.erase(p);
            }
            p = q;
        }
        st.emplace(l, r);
        cnt += r - l + 1;
    }
    
    int count() {
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    CountIntervals ci;
    vector<string> m{"count", "add", "add", "add", "add", "add", "count", "add", "add"};
    vector<vector<int>> v{ {}, { 8, 43 }, { 13, 16 }, { 26, 33 }, { 28, 36 }, { 29, 37 }, {}, { 34, 46 }, { 10, 23 } };
    int n = m.size();
    for (int i = 0; i < n; ++i) {
        if (m[i] == "add") {
            ci.add(v[i][0], v[i][1]);
        } else {
            cout << ci.count() << endl;
        }
    }
    return 0;
}
