#include "usual.h"

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> scores(n);
        for (int i = 0; i < n; ++i) {
            scores[edges[i]] += i;
        }
        long long max_score = -1, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (scores[i] > max_score) {
                ans = i;
                max_score = scores[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
