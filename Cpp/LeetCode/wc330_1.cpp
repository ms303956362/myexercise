#include "usual.h"

class Solution {
public:
    int distinctIntegers(int n) {
        set<int> st;
        st.insert(n);
        for (int k = 0; k < 1000; ++k) {
            for (const auto& x : st) {
                for (int i = 1; i <= n; ++i) {
                    if (x % i == 1) {
                        st.insert(i);
                    }
                }
            }
        }
        return st.size();
    }
};

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 100; ++i) {
        cout << Solution().distinctIntegers(i) << " ";
    }
    cout << endl;
    return 0;
}
