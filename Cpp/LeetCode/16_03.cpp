#include "usual.h"

class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector<double> v;
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
        int xl1min = x1 > x2 ? x2 : x1, xl1max = x1 > x2 ? x1 : x2;
        int xl2min = x3 > x4 ? x4 : x3, xl2max = x3 > x4 ? x3 : x4;
        int yl1min = y1 > y2 ? y2 : y1, yl1max = y1 > y2 ? y1 : y2;
        int yl2min = y3 > y4 ? y4 : y3, yl2max = y3 > y4 ? y3 : y4;
        int d = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
        int n = (y3-y4)*(y2*(x1-x2)-x2*(y1-y2)) - (y1-y2)*(y4*(x3-x4)-x4*(y3-y4));
        if (d == 0) { // 平行或重合
            if (n == 0) { // 重合
                if (x1 != x2) { // 不是平行y轴
                    // 用x判断
                    if (xl2min <= xl1min && xl1min <= xl2max) {
                        v.push_back(xl1min);
                        v.push_back(xl1min == x1 ? y1 : y2);
                    } else if (xl1min <= xl2min && xl2min <= xl1max) {
                        v.push_back(xl2min);
                        v.push_back(xl2min == x3 ? y3 : y4);
                    }
                } else { // 平行y轴
                    if (yl2min <= yl1min && yl1min <= yl2max) {
                        v.push_back(yl1min == y1 ? x1 : x2);
                        v.push_back(yl1min);
                    } else if (yl1min <= yl2min && yl2min <= yl1max) {
                        v.push_back(yl2min == y3 ? x3 : x4);
                        v.push_back(yl2min);
                    }
                }
            } // 平行v为空
        } else {
            double yi = static_cast<double>(n) / static_cast<double>(d), xi;
            if (y1 != y2) {
                xi = (x1 - x2) * (yi - y2) / (y1 - y2) + x2;
            } else {
                xi = (x3 - x4) * (yi - y4) / (y3 - y4) + x4;
            }
            if (xl1min <= xi && xi <= xl1max && xl2min <= xi && xi <= xl2max 
            && yl1min <= yi && yi <= yl1max && yl2min <= yi && yi <= yl2max) {
                v.push_back(xi);
                v.push_back(yi);
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> s1{1,0}, e1{1,1}, s2{-1,0}, e2{3,2};
    vector<double> v = Solution().intersection(s1, e1, s2, e2);
    return 0;
}
