#include "usual.h"

class MKAverage {
    multiset<int> s_min_k, s_max_k, s_mid;
    long long sum_min, sum_mid, sum_max;
    queue<int> q;
    int m, k;
public:
    MKAverage(int _m, int _k): m(_m), k(_k), sum_min(0), sum_mid(0), sum_max(0) {

    }
    
    void addElement(int num0) {
        q.push(num0);
        int num = num0;
        if (!s_min_k.empty() && num <= *s_min_k.rbegin()) {
            s_min_k.insert(num);
            sum_min += num;
        }
        else if (!s_max_k.empty() && *s_max_k.begin() <= num) {
            s_max_k.insert(num);
            sum_max += num;
        }
        else {
            s_mid.insert(num);
            sum_mid += num;
        }
        // while (s_max_k.size() > k) {
        //     auto p1 = prev(s_mid.end()), p2 = s_max_k.begin();
        //     sum_mid += *p2;
        //     sum_max -= *p2;
        //     s_mid.insert(*p2);
        //     s_max_k.erase(p2);
        // }
        // while (s_min_k.size() > k) {
        //     auto p1 = s_mid.begin(), p2 = prev(s_min_k.end());
        //     sum_mid += *p2;
        //     sum_min -= *p2;
        //     s_mid.insert(*p2);
        //     s_min_k.erase(p2);
        // }
        // while (s_max_k.size() < k) {
        //     auto p1 = prev(s_mid.end()), p2 = s_max_k.begin();
        //     sum_mid -= *p1;
        //     sum_max += *p1;
        //     s_max_k.insert(*p1);
        //     s_mid.erase(p1);
        // }
        // while (s_min_k.size() < k) {
        //     auto p1 = s_mid.begin(), p2 = prev(s_min_k.end());
        //     sum_mid -= *p1;
        //     sum_min += *p1;
        //     s_min_k.insert(*p1);
        //     s_mid.erase(p1);
        // }
        printf("%d %d %d\n", sum_min, sum_mid, sum_max);
        if (q.size() >= m) {
            if (q.size() > m) {
                num = q.front();
                q.pop();
                if (!s_min_k.empty() && *s_min_k.begin() <= num && num <= *s_min_k.rbegin()) {
                    s_min_k.erase(s_min_k.find(num));
                    sum_min -= num;
                }
                else if (!s_max_k.empty() && *s_max_k.begin() <= num && num <= *s_max_k.rbegin()) {
                    s_max_k.erase(s_max_k.find(num));
                    sum_max -= num;
                }
                else {
                    s_mid.erase(num);
                    sum_mid -= num;
                }
            }
            while (s_max_k.size() > k) {
                auto p2 = s_max_k.begin();
                sum_mid += *p2;
                sum_max -= *p2;
                s_mid.insert(*p2);
                s_max_k.erase(p2);
            }
            while (s_min_k.size() > k) {
                auto p2 = prev(s_min_k.end());
                sum_mid += *p2;
                sum_min -= *p2;
                s_mid.insert(*p2);
                s_min_k.erase(p2);
            }
            while (s_max_k.size() < k) {
                auto p1 = prev(s_mid.end());
                sum_mid -= *p1;
                sum_max += *p1;
                s_max_k.insert(*p1);
                s_mid.erase(p1);
            }
            while (s_min_k.size() < k) {
                auto p1 = s_mid.begin();
                sum_mid -= *p1;
                sum_min += *p1;
                s_min_k.insert(*p1);
                s_mid.erase(p1);
            }
            printf("%d %d %d\n", sum_min, sum_mid, sum_max);
        }
        cout << endl;
    }
    
    int calculateMKAverage() {
        if (q.size() < m)
            return -1;
        return sum_mid / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

int main(int argc, char const *argv[])
{
    int m = 3, k = 1;
    MKAverage* obj = new MKAverage(m, k);
    obj->addElement(17612);
    obj->addElement(74607);
    cout << obj->calculateMKAverage() << endl;
    obj->addElement(8272);
    obj->addElement(33433);
    cout << obj->calculateMKAverage() << endl;
    obj->addElement(15456);
    obj->addElement(64938);
    cout << obj->calculateMKAverage() << endl;
    obj->addElement(99741);
    // ["MKAverage","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement"]
    // [[3,1],[17612],[74607],[],[8272],[33433],[],[15456],[64938],[],[99741]]
    return 0;
}
