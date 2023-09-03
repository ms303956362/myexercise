#include "usual.h"

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
