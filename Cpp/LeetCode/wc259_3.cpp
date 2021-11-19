#include "usual.h"

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> cnt1, cnt2;

public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        if (!cnt1.count(point[0])) {
            cnt1[point[0]] = unordered_map<int, int>();
        }
        if (!cnt1[point[0]].count(point[1]))
            cnt1[point[0]][point[1]] = 0;
        ++cnt1[point[0]][point[1]];
        if (!cnt2.count(point[1])) {
            cnt2[point[1]] = unordered_map<int, int>();
        }
        if (!cnt2[point[1]].count(point[0]))
            cnt2[point[1]][point[0]] = 0;
        ++cnt2[point[1]][point[0]];
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        if (!cnt1.count(x))
            return 0;
        int ans = 0;
        for (const auto& [yy, cnt] : cnt1[x]) {
            int l = yy - y;
            if (l == 0)
                continue;
            if (cnt2[y].count(x + l) && cnt2.count(yy) && cnt2[yy].count(x + l))
                ans += cnt1[x][yy] * cnt1[x + l][y] * cnt1[x + l][yy];
            if (cnt2[y].count(x - l) && cnt2.count(yy) && cnt2[yy].count(x - l))
                ans += cnt1[x][yy] * cnt1[x - l][y] * cnt1[x - l][yy];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    DetectSquares detectSquares = DetectSquares();
    detectSquares.add({3, 10});
    detectSquares.add({11, 2});
    detectSquares.add({3, 2});
    detectSquares.count({11, 10}); // 返回 1 。你可以选择：
                                //   - 第一个，第二个，和第三个点
    detectSquares.count({14, 8});  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
    detectSquares.add({11, 2});    // 允许添加重复的点。
    detectSquares.count({11, 10}); // 返回 2 。你可以选择：
                                //   - 第一个，第二个，和第三个点
                                //   - 第一个，第三个，和第四个点
    return 0;
}
