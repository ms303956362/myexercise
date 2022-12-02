#include "usual.h"

class Solution {
public:
    string greatestLetter(string s) {
        vector<int> cnt1(26), cnt2(26);
        for (const auto& c : s) {
            if ('a' <= c && c <= 'z') {
                ++cnt1[c - 'a'];
            } else if ('A' <= c && c <= 'Z') {
                ++cnt2[c - 'A'];
            }
        }
        for (int i = 25; i >= 0; --i) {
            if (cnt1[i] > 0 && cnt2[i] > 0) {
                return string(1, i + 'A');
            }
        }
        return "";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
