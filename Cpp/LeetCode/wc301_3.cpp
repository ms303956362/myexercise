#include "usual.h"

class Solution {
public:
    bool canChange(string start, string target) {
        string s, t;
        vector<int> idx1, idx2;
        int n = start.size();
        for (int i = 0; i < n; ++i) {
            if (start[i] != '_') {
                s.push_back(start[i]);
                idx1.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (target[i] != '_') {
                t.push_back(target[i]);
                idx2.push_back(i);
            }
        }
        if (s != t) {
            return false;
        }
        int m = s.size();
        for (int i = 0; i < m; ++i) {
            if (s[i] == 'L') {
                if (idx1[i] < idx2[i]) {
                    return false;
                }
            } else {
                if (idx1[i] > idx2[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
