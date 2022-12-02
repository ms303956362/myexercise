#include "usual.h"

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size(), i = 0;
        int ans = 0;
        while (true) {
            int cnt = 0;
            while (i < n) {
                if (s[i] == '0') {
                    if (i + 1 < n && s[i + 1] == '1') {
                        swap(s[i], s[i + 1]);
                        ++cnt;
                        i += 2;
                    } else {
                        ++i;
                    }
                } else {
                    ++i;
                }
            }
            cout << s << endl;
            if (cnt == 0) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
