#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "MyQuote.h"

int main(int argc, char const *argv[])
{
    // 15.3
    // MyQuote mq("0-201-70353-X", 24.99);
    // print_total(cout, mq, 3);

    // 15.5
    // MyBulkQuote mbq("0-399-82477-1", 45.39, 3, 0.8);
    // print_total(cout, mbq, 2);
    // print_total(cout, mbq, 3);

    // 15.7
    // MyBulkQuotemax mbq("0-399-82477-1", 45.39, 3, 6, 0.8);
    // print_total(cout, mbq, 7);

    // 15.11
    // MyQuote mq("0-201-70353-X", 24.99);
    // MyBulkQuote mbq("0-399-82477-1", 45.39, 3, 0.8);
    // MyBulkQuotemax mbqm("0-201-78345-X", 25.00, 2, 5, 0.7);
    // mq.debug(cout) << endl;
    // mbq.debug(cout) << endl ;
    // mbqm.debug(cout) << endl;

    // 15.14
    MyBulkQuote mbq("0-399-82477-1", 45.39, 3, 0.8);
    MyQuote *pmq = &mbq;
    pmq->debug(cout);

    return 0;
}
