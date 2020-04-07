#include "usual.h"

class Solution {
public:
    int numSteps(string s) {
        int num = 0;
        while (s.size() > 1) {
            if (s.back() == '0')
                s.pop_back();
            else
                inc(s);
            ++num;
        }
        return num;
    }

    void inc(string& s) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                s[i] = '1';
                break;
            } else {
                s[i] = '0';
            }
        }
        if (s[0] == '0')
            s.insert(s.begin(), '1');
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().numSteps("1101") << endl;
    return 0;
}
