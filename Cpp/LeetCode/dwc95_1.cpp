#include "usual.h"

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long l = length, w = width, h = height, m = mass;
        string t1, t2;
        if (l >= 1e4 || w >= 1e4 || h >= 1e4 || l * w * h >= 1e9) {
            t1 = "Bulky";
        }
        if (m >= 100) {
            t2 = "Heavy";
        }
        if (t1 == "Bulky" && t2 == "Heavy") {
            return "Both";
        } else if (t1 == "" && t2 == "") {
            return "Neither";
        } else if (t1 == ""  && t2 == "Heavy") {
            return "Heavy";
        }
        return "Bulky";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
