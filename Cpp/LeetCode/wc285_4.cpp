#include "usual.h"

using ll = long long;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        map<int, int> ends;
        multiset<int> t;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            ends[j - 1] = i;
            t.insert(j - i);
            i = j;
        }
        auto merge = [&](int l, int r, int l1, int r1, int l2, int r2, int l3, int r3)
        {
            if (ends.count(r1)) {
                ends.erase(r1);
                t.erase(t.lower_bound(r1 - l1 + 1));
            }
            if (ends.count(r2)) {
                ends.erase(r2);
                t.erase(t.lower_bound(r2 - l2 + 1));
            }
            if (ends.count(r3)) {
                ends.erase(r3);
                t.erase(t.lower_bound(r3 - l3 + 1));
            }
            ends[r] = l;
            t.insert(r - l + 1);
        };
        auto split = [&](int l, int r, int l1, int r1, int l2, int r2, int l3, int r3)
        {
            if (ends.count(r)) {
                ends.erase(r);
                t.erase(t.lower_bound(r - l + 1));
            }
            if (r1 != -1) {
                ends[r1] = l1;
                t.insert(r1 - l1 + 1);
            }
            if (r2 != -1) {
                ends[r2] = l2;
                t.insert(r2 - l2 + 1);
            }
            if (r3 != -1) {
                ends[r3] = l3;
                t.insert(r3 - l3 + 1);
            }
        };
        int m = queryCharacters.size();
        vector<int> ans;
        for (int j = 0; j < m; ++j) {
            char c = queryCharacters[j];
            int i = queryIndices[j];
            if (s[i] == c) {
                continue;
            }
            auto p = ends.lower_bound(i);
            int r = p->first, l = p->second;
            // split
            if (i > 0 && s[i - 1] == s[i] && i < n - 1 && s[i] == s[i + 1]) {
                int l1 = ends[i - 1], r3 = ends.lower_bound(i + 1)->first;
                split(l, r, l1, i - 1, i, i, i + 1, r3);
            } else if (i > 0 && s[i - 1] == s[i]) {
                int l1 = ends[i - 1];
                split(l, r, l1, i - 1, i, i, -1, -1);
            } else if (i < n - 1 && s[i] == s[i + 1]) {
                int r3 = ends.lower_bound(i + 1)->first;
                split(l, r, -1, -1, i, i, i + 1, r3);
            }
            // merge
            if (i > 0 && s[i - 1] == c && i < n - 1 && c == s[i + 1]) {
                int l1 = ends[i - 1], r3 = ends.lower_bound(i + 1)->first;
                merge(l1, r3, l1, i - 1, i, i, i + 1, r3);
            } else if (i > 0 && s[i - 1] == c) {
                int l1 = ends[i - 1];
                merge(l1, i, l1, i - 1, i, i, -1, -1);
            } else if (i < n - 1 && c == s[i + 1]) {
                int r3 = ends.lower_bound(i + 1)->first;
                merge(i, r3, -1, -1, i, i, i + 1, r3);
            }
            // update
            s[i] = c;
            ans.push_back(*t.rbegin());
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s1("babacc"), s2("bcb");
    vector<int> q{1, 3, 3};
    Solution().longestRepeating(s1, s2, q);
    return 0;
}
