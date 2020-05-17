#include "usual.h"

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size(), cnt = 0;
        for (int i = 0; i != n; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
