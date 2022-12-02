#include "usual.h"

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int m = buses.size(), n = passengers.size();
        int i = 0, j = 0, cnt = 0;
        while (i < m) {
            cnt = 0;
            while (j < n && passengers[j] <= buses[i] && cnt < capacity) {
                ++j;
                ++cnt;
            }
            ++i;
        }
        unordered_set<int> s, tmp(passengers.begin(), passengers.end());
        for (const auto& b : buses) {
            if (!tmp.count(b)) {
                s.insert(b);
            }
        }
        for (const auto& p : passengers) {
            s.insert(p - 1);
        }
        vector<int> times(s.begin(), s.end());
        sort(times.begin(), times.end());
        if (cnt < capacity) {
            int l = times.size() - 1;
            while (l >= 0 && times[l] > buses[i - 1]) {
                --l;
            }
            return times[l];
        }
        --j;
        while (j > 0 && passengers[j] == passengers[j - 1] + 1) {
            --j;
        }
        return passengers[j] - 1;
    }
};

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        unordered_set<int> s, tmp(passengers.begin(), passengers.end());
        for (const auto& b : buses) {
            if (!tmp.count(b)) {
                s.insert(b);
            }
        }
        for (const auto& p : passengers) {
            s.insert(p - 1);
        }
        vector<int> times(s.begin(), s.end());
        sort(times.begin(), times.end());
        int l = 0, h = times.size() - 1;
        while (l <= h) {
            int m = (l + h) / 2;

        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
