#include "usual.h"

class Solution {
public:
    double chipGame(vector<int>& nums, int kind) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        queue<vector<int>> q;
        q.push(vector<int>(n));
        double ans = 0;
        while (!q.empty()) {
            int l = q.size();
            double sum = 0;
            for (int i = 0; i < l; ++i) {
                vector<int> state = q.front();
                q.pop();
                int j = 0;
                int diff = 0;
                while (j < n) {
                    int k = j + 1;
                    while (k < n && state[k] == state[k - 1]) {
                        ++k;
                    }
                    if (state[j] == 0) {

                    } else {
                        
                    }
                    ++diff;
                    j = k;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
