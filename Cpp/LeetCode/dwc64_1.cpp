#include "usual.h"

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> s;
        for (const auto& st : arr) {
            if (!s.count(st))
                s[st] = 0;
            ++s[st];
        }
        int cnt = 0;
        for (const auto& st : arr) {
            if (s[st] == 1)
                ++cnt;
            if (cnt == k)
                return st;
        }
        return "";
    }
};