#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
using std::copy;
using std::find;
using std::sort;
using std::unique_copy;

#include <numeric>
using std::accumulate;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <deque>
using std::deque;

#include <forward_list>
using std::forward_list;

#include <iterator>
using std::back_inserter;
using std::front_inserter;
using std::inserter;
using std::reverse_iterator;

#include "Sales_item.h"

template<typename Seq_iter>
void print_seq(const Seq_iter& beg, const Seq_iter& end, ostream& os=cout){
    for (auto iter = beg; iter != end;++iter){
        os << *iter << " ";
    }
    cout << endl;
}

bool compareISBN(const Sales_item& s1, const Sales_item& s2){
    return s1.isbn() < s2.isbn();
}

void classify_int(const string& in_file, const string& out_file1, const string& out_file2){
    ifstream ifs(in_file);
    ofstream ofs1(out_file1), ofs2(out_file2);
    istream_iterator<int> in_iter(ifs), eof;
    ostream_iterator<int> out_iter1(ofs1, " "), out_iter2(ofs2, " ");
    while (in_iter != eof){
        int i = *in_iter++;
        if (i % 2)
        {
            *out_iter1++ = i;
        } else {
            *out_iter2++ = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    // 10.27
    // vector<int> iv{1, 2, 2, 3, 4, 5, 5};
    // list<int> il;
    // unique_copy(iv.begin(), iv.end(), back_inserter(il));
    // print_seq(il.begin(), il.end());

    // 10.28
    // vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // list<int> il;
    // forward_list<int> ifl;
    // deque<int> id;
    // copy(iv.begin(), iv.end(), back_inserter(il));
    // copy(iv.rbegin(), iv.rend(), front_inserter(ifl));
    // copy(iv.begin(), iv.end(), inserter(id, id.begin()));
    // print_seq(il.begin(), il.end());
    // print_seq(ifl.begin(), ifl.end());
    // print_seq(id.begin(), id.end());

    // 10.29
    // ifstream ifs("data/accum");
    // istream_iterator<string> iter(ifs), eof;
    // vector<string> sv(iter, eof);
    // print_seq(sv.begin(), sv.end());

    // 10.30
    // istream_iterator<int> in_iter(cin), eof;
    // ostream_iterator<int> out_iter(cout, " ");
    // vector<int> iv(in_iter, eof);
    // sort(iv.begin(), iv.end());
    // copy(iv.begin(), iv.end(), out_iter);

    // 10.31
    // istream_iterator<int> in_iter(cin), eof;
    // ostream_iterator<int> out_iter(cout, " ");
    // vector<int> iv(in_iter, eof);
    // sort(iv.begin(), iv.end());
    // unique_copy(iv.begin(), iv.end(), out_iter);

    // 10.32
    // ifstream ifs("data/book_sales");
    // istream_iterator<Sales_item> iter(ifs), eof;
    // vector<Sales_item> sdv(iter, eof);
    // sort(sdv.begin(), sdv.end(), compareISBN);
    // for (auto beg = sdv.begin(), end = beg; beg != sdv.end(); beg = end){
    //     Sales_item sum(beg->isbn());
    //     end = find_if(beg, sdv.end(), [beg](const Sales_item &s) { return beg->isbn() != s.isbn(); });
    //     cout << accumulate(beg, end, sum) << endl;
    // }

    // 10.33
    // classify_int("data/iostream_iter", "data/odd", "data/even");

    // 10.34
    // ostream_iterator<int> iter(cout, " ");
    // vector<int> iv{1, 2, 3, 4, 5, 6};
    // copy(iv.crbegin(), iv.crend(), iter);

    // 10.35
    // vector<int> iv{1, 2, 3, 4, 5, 6};
    // for (auto iter = iv.end() - 1; iter != iv.begin() - 1; --iter)
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;

    // 10.36
    // list<int> iv{0, 1, 2, 3, 4, 5, 0, 6};
    // auto iter = find(iv.crbegin(), iv.crend(), 0);
    // cout << *++iter << " "<< *--iter << " " << *--iter << endl;

    // 10.37
    vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> il;
    copy(iv.rend() - 7, iv.rend() - 2, back_inserter(il));
    print_seq(il.begin(), il.end());

    return 0;
}
