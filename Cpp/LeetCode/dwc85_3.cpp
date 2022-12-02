#include "usual.h"

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1);
        for (const auto& sf : shifts) {
            if (sf[2] == 0) {
                diff[sf[0]] -= 1;
                diff[sf[1]] += 1;
            } else {
                diff[sf[0]] += 1;
                diff[sf[1]] -= 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
            int mv = sum;
            if (mv < 0) {
                mv += (-mv + 25) / 26 * 26;
            }
            s[i] = (s[i] - 'a' + mv) % 26 + 'a';
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
