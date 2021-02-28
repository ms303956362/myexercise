#include "usual.h"

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (s.size() && (cars[i][1] <= cars[s.top()][1] || (res[s.top()] >= 0 && (double)(cars[s.top()][0] - cars[i][0]) / (double)(cars[i][1] - cars[s.top()][1]) >= res[s.top()]))) {
                s.pop();
            }
            if (s.size())
                res[i] = (double)(cars[s.top()][0] - cars[i][0]) / (double)(cars[i][1] - cars[s.top()][1]);
            s.push(i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
