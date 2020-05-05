#include "usual.h"

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        bool ok1 = true, ok2 = true;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i != n; ++i) {
            if (s1[i] < s2[i]) {
                ok1 = false;
                break;
            }
        }
        for (int i = 0; i != n; ++i) {
            if (s2[i] < s1[i]) {
                ok2 = false;
                break;
            }
        }
        return ok1 || ok2;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().checkIfCanBreak("abc", "xya") << endl;
    cout << Solution().checkIfCanBreak("abe", "acd") << endl;
    cout << Solution().checkIfCanBreak("leetcodee", "interview") << endl;
    return 0;
}
