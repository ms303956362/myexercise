#include "usual.h"

class RangeFreqQuery {
    unordered_map<int, vector<int>> indices;

public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            indices[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (!indices.count(value))
            return 0;
        const auto &idx = indices[value];
        int l = lower_bound(idx.begin(), idx.end(), left) - idx.begin();
        int r = upper_bound(idx.begin(), idx.end(), right) - idx.begin();
        return r - l;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
