#include "usual.h"

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<string> v;
        for (int i = 0; i < n; ++i) {
            if (number[i] == digit) {
                string s;
                for (int j = 0; j < n; ++j) {
                    if (j == i) {
                        continue;
                    }
                    s.push_back(number[j]);
                }
                v.push_back(s);
            }
        }
        sort(v.begin(), v.end());
        return v.back();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
