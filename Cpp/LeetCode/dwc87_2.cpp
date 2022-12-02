#include "usual.h"

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size(), n = trainers.size();
        int i = 0, j = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        while (i < m && j < n) {
            while (j < n && players[i] > trainers[j]) {
                ++j;
            }
            if (j < n && players[i] <= trainers[j]) {
                ++ans;
            }
            ++i;
            ++j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
