#include "usual.h"

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int, long long> last;
        long long day = 0;
        for (const auto& task : tasks) {
            if (!last.count(task) || day - last[task] > space) {
                ++day;
            } else {
                day = last[task] + space + 1;
            }
            last[task] = day;
        }
        return day;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
