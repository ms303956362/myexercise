#include "usual.h"

class Solution {
public:
    int countTime(string time) {
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            if (i > 0 && time[0] != '?') {
                break;
            }
            for (int j = 0; j < 10; ++j) {
                if (j > 0 && time[1] != '?') {
                    break;
                }
                for (int k = 0; k < 10; ++k) {
                    if (k > 0 && time[3] != '?') {
                        break;
                    }
                    for (int l = 0; l < 10; ++l) {
                        if (l > 0 && time[4] != '?') {
                            break;
                        }
                        string tmp(time);
                        for (int t = 0; t < 5; ++t) {
                            if (tmp[t] == '?') {
                                if (t == 0) {
                                    tmp[t] = i + '0';
                                } else if (t == 1) {
                                    tmp[t] = j + '0';
                                } else if (t == 3) {
                                    tmp[t] = k + '0';
                                } else if (t == 4) {
                                    tmp[t] = l + '0';
                                }
                            }
                        }
                        int h = stoi(tmp.substr(0, 2)), m = stoi(tmp.substr(3, 2));
                        if (0 <= h && h <= 23 && 0 <= m && m <= 59) {
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
