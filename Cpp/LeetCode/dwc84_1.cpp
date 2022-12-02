#include "usual.h"

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> weights;
        for (const auto& v : items1) {
            weights[v[0]] += v[1];
        }
        for (const auto& v : items2) {
            weights[v[0]] += v[1];
        }
        vector<vector<int>> ans;
        for (const auto& [v, w] : weights) {
            ans.push_back({v, w});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
