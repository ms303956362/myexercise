#include "usual.h"

class Solution {
public:
    int minSwaps(string s) {
        int cnt_1 = 0, cnt_0 = 0;
        for (const auto& c : s) {
            if (c == '1')
                ++cnt_1;
            else
                ++cnt_0;
        }
        if (!(cnt_1 == cnt_0 || cnt_1 - cnt_0 == 1 || cnt_0 - cnt_1 == 1))
            return -1;
        int n = s.size();
        int odd_1 = 0, even_1 = 0, odd_0 = 0, even_0 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i % 2 == 0)
                    ++even_1;
                else
                    ++odd_1;
            } else {
                if (i % 2 == 0)
                    ++even_0;
                else
                    ++odd_0;
            }
        }
        // cout << odd_1 << " " << even_1 << " " << odd_0 << " " << even_0 << endl;
        if (cnt_1 == cnt_0) {
            return min(odd_1, even_1);
        } else {
            if (odd_1 == even_0)
                return odd_1;
            else
                return odd_0;
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
