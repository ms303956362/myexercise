#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <vector>
using std::vector;

#include <set>
using std::multiset;

#include "MyQuote.h"

class Basket {
public:
    void add_item(shared_ptr<MyQuote> &pmq) { pmq_set.insert(pmq); }
    void add_item(const MyQuote &mq) { pmq_set.insert(shared_ptr<MyQuote>(mq.clone())); }
    void add_item(MyQuote &&mq) { pmq_set.insert(shared_ptr<MyQuote>(mq.clone())); }
    double total_receipt(ostream& os) {
        double sum = 0;
        for (auto iter = pmq_set.cbegin(); iter != pmq_set.cend();iter = pmq_set.upper_bound(*iter)){
            sum += print_total(os, **iter, pmq_set.count(*iter));
        }
        os << "Total Sale: " << sum << endl;
        return sum;
    }

private:
    static bool compare(const shared_ptr<MyQuote> &lpmq, const shared_ptr<MyQuote> &rpmq) { return lpmq->isbn() < rpmq->isbn(); }
    multiset<shared_ptr<MyQuote>, decltype(compare)*> pmq_set{compare};
};
int main(int argc, char const *argv[])
{
    // 15.28
    // MyQuote mq("0-201-70353-X", 25);
    // MyBulkQuote mbq("0-201-70355-X", 25, 2, 0.8);
    // vector<MyQuote> basket;
    // double sum1, sum2;
    // basket.push_back(mq);
    // basket.push_back(mbq);
    // cout << (sum1 = basket.back().net_price(2)) << endl;
    // cout << (sum2 = basket.front().net_price(3)) << endl;
    // cout << "Total Sale: " << sum1 + sum2 << endl;

    // 15.29
    // shared_ptr<MyQuote> pmq = make_shared<MyQuote>("0-201-70353-X", 25);
    // shared_ptr<MyBulkQuote> pmbq = make_shared<MyBulkQuote>("0-201-70355-X", 25, 2, 0.8);
    // vector<shared_ptr<MyQuote>> basket;
    // double sum1, sum2;
    // basket.push_back(pmq);
    // basket.push_back(pmbq);
    // cout << (sum1 = basket.front()->net_price(2)) << endl;
    // cout << (sum2 = basket.back()->net_price(3)) << endl;
    // cout << "Total Sale: " << sum1 + sum2 << endl;

    // 15.30
    MyQuote mq("0-201-70353-X", 25);
    MyBulkQuote mbq("0-201-70355-X", 25, 2, 0.8);
    Basket bsk;
    bsk.add_item(mq);
    bsk.add_item(mq);
    bsk.add_item(mbq);
    bsk.add_item(mbq);
    bsk.add_item(mbq);
    bsk.total_receipt(cout);

    return 0;
}
