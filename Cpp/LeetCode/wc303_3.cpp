#include "usual.h"

class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cus2tree;
    unordered_map<string, unordered_map<string, set<pair<int, string>>::iterator>> cus2food2iter;
    unordered_map<string, string> food2cus;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            food2cus[foods[i]] = cuisines[i];
            auto [p, ok] = cus2tree[cuisines[i]].emplace(-ratings[i], foods[i]);
            cus2food2iter[cuisines[i]][foods[i]] = p;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cus = food2cus[food];
        auto p = cus2food2iter[cus][food];
        cus2tree[cus].erase(p);
        auto [q, ok] = cus2tree[cus].emplace(-newRating, food);
        cus2food2iter[cus][food] = q;
    }
    
    string highestRated(string cuisine) {
        return cus2tree[cuisine].begin()->second;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
