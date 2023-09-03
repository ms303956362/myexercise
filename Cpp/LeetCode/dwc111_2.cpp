#include "usual.h"

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if (n1 < n2) {
            return false;
        }
        if (str1 == str2) {
            return true;
        }
        int i = 0, j = 0;
        auto nxt = [](char c) {
            return c == 'z' ? 'a' : (c + 1);
        };
        while (i < n1 && j < n2) {
            while (i < n1 && (str2[j] != str1[i] && str2[j] != nxt(str1[i]))) {
                ++i;
            }
            if (i == n1) {
                return false;
            }
            ++i;
            ++j;
        }
        return j == n2;
    }
};