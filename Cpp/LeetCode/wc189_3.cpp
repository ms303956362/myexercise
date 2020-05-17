#include "usual.h"

struct Pair {
    int i;
    string s;
    Pair(int ii=0, string ss="") : i(ii), s(ss) {}
};

bool operator<(const Pair &l, const Pair &r) { return l.s < r.s; }

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& vvs) {
        int n = vvs.size();
        vector<Pair> vs(n);
        for (int i = 0; i != n; ++i) {
            sort(vvs[i].begin(), vvs[i].end());
            string s;
            for (int j = 0; j != vvs[i].size(); ++j)
                s += vvs[i][j];
            vs[i] = Pair(i, s);
        }
        sort(vs.begin(), vs.end());
        vector<int> res;
        for (int i = 0; i != n - 1; ++i) {
            if (!(vs[i].s.size() < vs[i + 1].s.size() && vs[i].s == vs[i + 1].s.substr(0, vs[i].s.size()))) {
                res.push_back(vs[i].i);
            }
        }
        res.push_back(vs[n - 1].i);
        sort(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> vvs{{"nxaqhyoprhlhvhyojanr","ovqdyfqmlpxapbjwtssm","qmsbphxzmnvflrwyvxlc","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"},{"nxaqhyoprhlhvhyojanr","ovqdyfqmlpxapbjwtssm","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"},{"ovqdyfqmlpxapbjwtssm","qmsbphxzmnvflrwyvxlc","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"}};
    Solution().peopleIndexes(vvs);
    return 0;
}
