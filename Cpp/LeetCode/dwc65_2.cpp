#include "usual.h"

class Robot {
    int d;
    int x;
    int y;
    int w;
    int h;
    bool ok;
    vector<pair<int, int>> dirs;
    vector<string> dirs_names;

public:
    Robot(int width, int height): d(0), x(0), y(0), w(width), h(height) {
        ok = false;
        dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        dirs_names = {"East", "North", "West", "South"};
    }
    
    void move(int num) {
        num %= (w + h - 2) * 2;
        if (num == 0 && !ok) {
            d = 3;
        }
        ok = true;
        for (int i = 0; i < num; ++i) {
            while (!(0 <= x + dirs[d].first && x + dirs[d].first < w && 0 <= y + dirs[d].second && y + dirs[d].second < h))
                d = (d + 1) % 4;
            x += dirs[d].first;
            y += dirs[d].second;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs_names[d];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
