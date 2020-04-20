#include "usual.h"

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<vector<string>> v(n, vector<string>());
        v[0].push_back("a");
        v[0].push_back("b");
        v[0].push_back("c");
        for (int i = 1; i != n; ++i) {
            for (auto& s : v[i-1]) {
                if (s.back() == 'a') {
                    v[i].push_back(s + "b");
                    v[i].push_back(s + "c");
                }
                else if (s.back() == 'b') {
                    v[i].push_back(s + "a");
                    v[i].push_back(s + "c");
                } else {
                    v[i].push_back(s + "a");
                    v[i].push_back(s + "b");
                }
            }
        }
        if (v[n - 1].size() < k)
            return "";
        else
            return v[n - 1][k - 1];
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().getHappyString(10, 100) << endl;
    return 0;
}
