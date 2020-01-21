#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "my_Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // 8.4
    // ifstream ifs("data/sstream");
    // vector<string> v;
    // if (ifs){
    //     string s;
    //     while (getline(ifs, s))
    //         v.push_back(s);
    //     for (auto e : v)
    //         cout << e << endl;
    // }else{
    //     cerr << "open file failed" << endl;
    // }

    // 8.5
    // ifstream ifs("data/sstream");
    // vector<string> v;
    // if (ifs){
    //     string s;
    //     while (ifs >> s)
    //         v.push_back(s);
    //     for (auto e : v)
    //         cout << e << endl;
    // }else{
    //     cerr << "open file failed" << endl;
    // }

    // 8.6
    // ifstream ifs(argv[1]);
    // Sales_data total(ifs);
    // if (ifs){
    //     Sales_data trans;
    //     while (read(ifs, trans)){
    //         if (total.isbn() == trans.isbn()){
    //             total.combine(trans);
    //         } else {
    //             print(cout, total) << endl;
    //             total = trans;
    //         }
    //     }
    //     print(cout, total) << endl;
    // } else {
    //     cerr << "open file failed" << endl;
    // }

    // 8.7
    // ifstream ifs(argv[1]);
    // ofstream ofs(argv[2]);
    // Sales_data total(ifs);
    // if (ifs){
    //     Sales_data trans;
    //     while (read(ifs, trans)){
    //         if (total.isbn() == trans.isbn()){
    //             total.combine(trans);
    //         } else {
    //             print(ofs, total) << endl;
    //             total = trans;
    //         }
    //     }
    //     print(ofs, total) << endl;
    // } else {
    //     cerr << "open file failed" << endl;
    // }

    // 8.8
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2], ofstream::app);
    Sales_data total(ifs);
    if (ifs){
        Sales_data trans;
        while (read(ifs, trans)){
            if (total.isbn() == trans.isbn()){
                total.combine(trans);
            } else {
                print(ofs, total) << endl;
                total = trans;
            }
        }
        print(ofs, total) << endl;
    } else {
        cerr << "open file failed" << endl;
    }

    return 0;
}
