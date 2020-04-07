#include "usual.h"

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x1 <= x_center  && x_center <= x2 && y1 <= y_center  && y_center <= y2)
            return true;
        int x_near = (abs(x1 - x_center) < abs(x2 - x_center) ? x1 : x2);
        int y_near = (abs(y1 - y_center) < abs(y2 - y_center) ? y1 : y2);
        if (x1 <= x_center  && x_center <= x2 && abs(y_near - y_center) <= radius)
            return true;
        if (y1 <= y_center  && y_center <= y2 && abs(x_near - x_center) <= radius)
            return true;
        if (distance(x_near, y_near, x_center, y_center) <= radius)
            return true;
        return false;
    }

    double distance(int x1, int y1, int x2, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().checkOverlap(1, 1, 1, 1, -3, 2, -1) << endl;
    return 0;
}
