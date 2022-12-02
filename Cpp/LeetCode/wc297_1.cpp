#include "usual.h"

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int last = 0;
        for (const auto& v : brackets) {
            if (income > v[0]) {
                ans += (v[0] - last) * v[1] / 100.0;
                last = v[0];
            } else {
                ans += (income - last) * v[1] / 100.0;
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
