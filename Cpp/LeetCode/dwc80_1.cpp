#include "usual.h"

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8) {
            return false;
        }
        int cnt_lower = 0, cnt_upper = 0, cnt_digit = 0, cnt_sp = 0;
        string s("!@#$%^&*()-+");
        unordered_set<char> st(s.begin(), s.end());
        for (const auto &c : password) {
            if ('a' <= c && c <= 'z') {
                ++cnt_lower;
            } else if ('A' <= c && c <= 'Z') {
                ++cnt_upper;
            } else if ('0' <= c && c <= '9') {
                ++cnt_digit;
            } else if (st.count(c)) {
                ++cnt_sp;
            }
        }
        if (cnt_lower == 0 || cnt_upper == 0 || cnt_sp == 0 || cnt_digit == 0) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (password[i] == password[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
