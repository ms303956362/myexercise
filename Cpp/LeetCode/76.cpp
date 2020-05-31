#include "usual.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int cnt_s[128], cnt_t[128];
        char min_c = 127, max_c = 0;
        bool ok = false;
        memset(cnt_s, 0, 128 * sizeof(int));
        memset(cnt_t, 0, 128 * sizeof(int));
        for(const auto& c : t) {
            ++cnt_t[c];
            min_c = min(min_c, c);
            max_c = max(max_c, c);
        }
        string min_str = s;
        queue<int> q;
        for (int i = 0, j = 0, k; i != s.size(); ++i) {
            if (cnt_t[s[i]] != 0) {
                ++cnt_s[s[i]];
                q.push(i);
            } else {
                continue;
            }
            for (k = min_c; k <= max_c; ++k) {
                if (cnt_s[k] < cnt_t[k])
                    break;
            }
            if (k <= max_c)
                continue;
            ok = true;
            for (j = q.front(); cnt_s[s[j]] > cnt_t[s[j]]; j = q.front()) {
                --cnt_s[s[j]];
                q.pop();
            }
            string str(s.begin() + j, s.begin() + i + 1);
            min_str = (str.size() < min_str.size() ? str : min_str);
            --cnt_s[s[j]];
            j = q.front();
            q.pop();
        }
        return ok ? min_str : "";
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
