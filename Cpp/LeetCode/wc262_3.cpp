#include "usual.h"

class StockPrice {
    int curr_time;
    int curr_price;
    multiset<int> ps;
    unordered_map<int, multiset<int>::iterator> m;

public:
    StockPrice(): curr_time(-1) {

    }
    
    void update(int timestamp, int price) {
        if (timestamp > curr_time) {
            curr_time = timestamp;
            curr_price = price;
        }
        if (m.count(curr_time)) {
            ps.erase(m[timestamp]);
        }
        m[timestamp] = ps.insert(price);
    }
    
    int current() {
        return curr_price;
    }
    
    int maximum() {
        return *ps.rbegin();
    }
    
    int minimum() {
        return *ps.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

/*
["StockPrice","update","maximum","current","minimum","maximum","maximum","maximum","minimum","minimum","maximum","update","maximum","minimum","update","maximum","minimum","current","maximum","update","minimum","maximum","update","maximum","maximum","current","update","current","minimum","update","update","minimum","minimum","update","current","update","maximum","update","minimum"]
[[],[38,2308],[],[],[],[],[],[],[],[],[],[47,7876],[],[],[58,1866],[],[],[],[],[43,121],[],[],[40,5339],[],[],[],[32,5339],[],[],[43,6414],[49,9369],[],[],[36,3192],[],[48,1006],[],[53,8013],[]]

["StockPrice","update","minimum","update","update","minimum","minimum","update","maximum","update","minimum","current","minimum","update","current","minimum","current","current","update","maximum","maximum","update","minimum","minimum","maximum","maximum","update","maximum","current","maximum","minimum","minimum","update","current"]
[[],[45,9233],[],[55,9651],[37,3902],[],[],[25,4833],[],[53,4521],[],[],[],[22,1161],[],[],[],[],[55,6897],[],[],[20,5354],[],[],[],[],[30,5623],[],[],[],[],[],[25,2725],[]]

[null,null,9233,null,null,3902,3902,null,9651,null,3902,9651,3902,null,9651,1161,9651,9651,null,9233,9233,null,1161,1161,9233,9233,null,9233,9651,9233,1161,1161,null,9651]

[null,null,9233,null,null,3902,3902,null,9651,null,3902,9651,3902,null,9651,1161,9651,9651,null,9233,9233,null,1161,1161,9233,9233,null,9233,6897,9233,1161,1161,null,6897]


*/

int main(int argc, char const *argv[])
{
    
    return 0;
}
