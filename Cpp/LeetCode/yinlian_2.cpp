#include "usual.h"

struct ActNode {
    int actId;
    int pl;
    int dis;
    int num;
    int ul;
    unordered_map<int, int> us;
    ActNode() = default;
    ActNode(int aid, int p, int d, int n, int u): actId(aid), pl(p), dis(d), num(n), ul(u) {}
};

class DiscountSystem {
    unordered_map<int, ActNode> al;

public:
    DiscountSystem() {

    }
    
    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        al.insert(make_pair(actId, ActNode(actId, priceLimit, discount, number, userLimit)));
    }
    
    void removeActivity(int actId) {
        if (al.count(actId)) {
            al.erase(actId);
        }
    }
    
    int consume(int userId, int cost) {
        int min_aid = INT_MAX, min_cost = INT_MAX;
        for (auto& [aid, an] : al) {
            if (an.num > 0 && an.us[userId] < an.ul && cost >= an.pl) {
                if (cost - an.dis < min_cost || cost - an.dis == min_cost && an.actId < min_aid) {
                    min_aid = an.actId;
                    min_cost = cost - an.dis;
                }
            }
        }
        if (min_aid != INT_MAX && min_cost != INT_MAX) {
            --al[min_aid].num;
            if (!al[min_aid].us.count(userId)) {
                al[min_aid].us[userId] = 0;
            }
            ++al[min_aid].us[userId];
            return cost - al[min_aid].dis;
        }
        return cost;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
