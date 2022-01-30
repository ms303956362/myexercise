#include "usual.h"

class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<int>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (int i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline int lowBit(int i) { return i & (-i); }

    void update(int i, int delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    int query(int i) {
        ++i;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        vector<int> st1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')' && locked[i] == '0') {
                st1.push_back(i);
            }
            if (s[i] == '(')
                ++cnt;
            else
                --cnt;
            while (cnt < 0 && st1.size() > 0) {
                st1.pop_back();
                cnt += 2;
            }
            if (cnt < 0)
                return false;
        }
        if (cnt == 0)
            return true;
        if (cnt < 0)
            return false;
        if (cnt % 2 != 0)
            return false;
        int min_cnt = cnt, cnt2 = 0;
        vector<int> st2;
        for (int i = n - 1; i >= 0; --i) {
            min_cnt = min(min_cnt, cnt);
            if (s[i] == '(' && locked[i] == '0') {
                st2.push_back(i);
            }
            if (s[i] == '(')
                --cnt2;
            else
                ++cnt2;
            while (cnt2 < 0 && st2.size() > 0) {
                st2.pop_back();
                cnt2 += 2;
                min_cnt -= 2;
                cnt -= 2;
                if (min_cnt < 0)
                    return false;
                if (cnt == 0)
                    return true;
            }
            if (cnt2 < 0)
                return false;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string s1("())(()(()(())()())(())((())(()())((())))))(((((((())(()))))("),
        s2("100011110110011011010111100111011101111110000101001101001111");
    Solution().canBeValid(s1, s2);
    return 0;
}
