#include "temperature.h"
#include "rangeTree.h"

int main(int argc, char const *argv[])
{
    int n = GetNumOfStation();
    // 预处理
    Station *s = new Station[n];
    for (int i = 0; i != n; ++i) {
        int x, y, t;
        GetStationInfo(i, &x, &y, &t);
        s[i] = Station(x, y, t);
    }
    int x1, y1, x2, y2;
    int avg_temp;
    RangeTree r(s, n);
    while (GetQuery(&x1, &y1, &x2, &y2)) {
        // start query
        avg_temp = x1;
        // end query
        Response(avg_temp);
    }
    return 0;
}
