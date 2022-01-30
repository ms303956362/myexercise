#include "usual.h"

class RangeModule {
    map<int, int> ends;

public:
    RangeModule() {

    }
    
    void addRange(int left, int right) {
        --right;
        cout << "add(" << left << ", " << right << ")" << endl;
        auto p = ends.lower_bound(left - 1);
        while (p != ends.end()) {
            if (p->second > right + 1)
                break;
            left = min(left, p->second);
            right = max(right, p->first);
            auto tmp = p;
            ++p;
            ends.erase(tmp);
        }
        ends[right] = left;
        for (const auto& [r, l] : ends) {
            cout << "[" << l << ", " << r << "] ";
        }
        cout << endl;
    }
    
    bool queryRange(int left, int right) {
        --right;
        auto p = ends.lower_bound(right);
        cout << "query(" << left << ", " << right << "): " << (p != ends.end() && p->second <= left) << endl;
        return p != ends.end() && p->second <= left;
    }
    
    void removeRange(int left, int right) {
        --right;
        vector<pair<int, int>> add;
        auto p = ends.lower_bound(left);
        while (p != ends.end()) {
            if (p->second > right)
                break;
            if (p->second < left) {
                add.emplace_back(p->second, left - 1);
            }
            if (p->first > right) {
                add.emplace_back(right + 1, p->first);
            }
            auto tmp = p;
            ++p;
            ends.erase(tmp);
        }
        for (const auto& [l, r] : add) {
            ends[r] = l;
        }
        cout << "remove(" << left << ", " << right << ")" << endl;
        for (const auto& [r, l] : ends) {
            cout << "[" << l << ", " << r << "] ";
        }
        cout << endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */


int main(int argc, char const *argv[])
{
    RangeModule* obj = new RangeModule();
    obj->addRange(14,100);
    obj->removeRange(1,8);
    obj->queryRange(77,80);
    obj->queryRange(8,43);
    obj->queryRange(4,13);
    obj->removeRange(3,9);
    obj->removeRange(45,49);
    obj->removeRange(41,90);
    obj->addRange(58,79);
    obj->addRange(4,83);
    obj->addRange(34,39);
    obj->removeRange(84,100);
    obj->addRange(8,9);
    obj->queryRange(32,56);
    obj->addRange(35,46);
    obj->addRange(9,100);
    obj->queryRange(85,99);
    obj->queryRange(23,33);
    obj->addRange(10,31);
    obj->removeRange(15,45);
    obj->removeRange(52,70);
    obj->removeRange(26,42);
    obj->queryRange(30,70);
    obj->queryRange(60,69);
    obj->addRange(10,94);
    obj->addRange(2,89);
    obj->queryRange(26,39);
    obj->addRange(46,93);
    obj->addRange(30,83);
    obj->removeRange(42,48);
    obj->addRange(47,74);
    obj->addRange(39,45);
    obj->queryRange(14,64);
    obj->removeRange(3,97);
    obj->queryRange(16,34);
    obj->removeRange(28,100);
    obj->addRange(19,37);
    obj->addRange(27,91);
    obj->queryRange(55,62);
    obj->removeRange(64,65);
    obj->removeRange(2,48);
    obj->addRange(55,78);
    obj->queryRange(21,89);
    obj->queryRange(31,76);
    obj->removeRange(13,32);
    obj->removeRange(2,84);
    obj->removeRange(21,88);
    obj->queryRange(12,31);
    obj->addRange(89,97);
    obj->removeRange(56,72);
    obj->removeRange(16,75);
    obj->queryRange(18,90);
    obj->removeRange(46,60);
    obj->removeRange(20,62);
    obj->queryRange(28,77);
    obj->addRange(5,78);
    obj->addRange(58,61);
    obj->removeRange(38,70);
    obj->queryRange(24,73);
    obj->queryRange(72,96);
    obj->addRange(5,24);
    obj->removeRange(43,49);
    obj->removeRange(2,20);
    obj->addRange(4,69);
    obj->addRange(18,98);
    obj->addRange(26,42);
    obj->addRange(14,18);
    obj->queryRange(46,58);
    obj->removeRange(16,90);
    obj->addRange(32,47);
    obj->addRange(19,36);
    obj->addRange(26,78);
    obj->queryRange(7,58);
    obj->addRange(42,54);
    obj->removeRange(42,83);
    obj->queryRange(3,83);
    obj->removeRange(54,82);
    obj->removeRange(71,91);
    obj->removeRange(22,37);
    obj->queryRange(38,94);
    obj->queryRange(20,44);
    obj->queryRange(37,89);
    obj->queryRange(15,54);
    obj->queryRange(1,64);
    obj->removeRange(63,65);
    obj->queryRange(55,58);
    obj->removeRange(23,44);
    obj->queryRange(25,87);
    obj->addRange(38,85);
    obj->queryRange(27,71);
    return 0;
}
