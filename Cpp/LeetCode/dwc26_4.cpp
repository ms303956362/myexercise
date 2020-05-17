#include "usual.h"

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> max_int(target + 1, "0");
        for (int i = 0; i != 9; ++i) {
            if (cost[i] > target)
                continue;
            string num = to_string(i + 1);
            if (lt(max_int[cost[i]], num))
                max_int[cost[i]] = num;
        }
        for (int i = 2; i <= target; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                if (max_int[j] != "0" && max_int[i - j] != "0") {
                    string s = merge(max_int[j], max_int[i - j]);
                    if (lt(max_int[i], s))
                        max_int[i] = s;
                }
            }
        }
        return max_int[target];
    }

    string merge(const string& s1, const string& s2) {
        int n1 = s1.size(), n2 = s2.size(), n = n1 + n2;
        string res(n, '0');
        int i = 0, j = 0, k = 0;
        while ( i != n1 && j != n2){
            if (s1[i] < s2[j])
                res[k++] = s2[j++];
            else
                res[k++] = s1[i++];
        }
        while (i != n1) 
            res[k++] = s1[i++];
        while (j != n2)
            res[k++] = s2[j++];
        return res;
    }

    inline bool lt(string ls, string rs) { // ls < rs
        return ls.size() < rs.size() || (ls.size() == rs.size() && ls < rs);
    }

    inline bool gt(string ls, string rs) { // ls > rs
        return ls.size() > rs.size() || (ls.size() == rs.size() && ls > rs);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> c{6,10,15,40,40,40,40,40,40};
    int t = 47;
    cout << Solution().largestNumber(c, t) << endl;
    return 0;
}
