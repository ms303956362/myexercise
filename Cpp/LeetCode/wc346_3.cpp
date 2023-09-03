#include "usual.h"

bool ok[1005];
bool is_init = false;

class Solution {
public:
    int punishmentNumber(int n) {
        if (!is_init) {
            auto check = [](int n) -> bool{
                string str = to_string(n * n);
                int l = str.size();
                for (int s = 0; s < (1 << (l - 1)); ++s) {
                    vector<string> v;
                    int last = 0;
                    for (int i = 0; i < l - 1; ++i) {
                         if (s & (1 << i)) {
                            v.push_back(str.substr(last, i - last + 1));
                            last = i + 1;
                         }
                    }
                    v.push_back(str.substr(last, l - last));
                    int sum = 0;
                    for (const auto& t : v) {
                        sum += stoi(t);
                    }
                    if (sum == n) {
                        return true;
                    }
                }
                return false;
            };
            for (int i = 1; i <= 1000; ++i) {
                ok[i] = check(i);
            }
            is_init = true;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (ok[i]) {
                ans += i * i;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
