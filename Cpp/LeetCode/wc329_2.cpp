#include "usual.h"

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&k](const auto& lv, const auto& rv) {
            return lv[k] > rv[k];
        });
        return score;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
