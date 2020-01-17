#include <iostream>
#include <string>

using std::ostream;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

// Sale_data类
struct Sales_data{
    // 构造函数
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s){};
    Sales_data(const string &s, unsigned i, double d) : bookNo(s), units_sold(i), revenue(d){};
    Sales_data(istream &is){
        double price;
        is >> bookNo >> units_sold >> price;
        revenue = units_sold * price;
    }
    // 成员函数
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    // 成员变量
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
};

Sales_data& Sales_data::combine(const Sales_data& item){
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

istream& read(istream& is, Sales_data& item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream& print(ostream& os, const Sales_data& item){
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.revenue / item.units_sold << endl;
    return os;
}

// Person类
struct Person;
istream &read_person(istream &is, Person &p);

struct Person{
    // 构造函数
    Person() = default;
    Person(const string &n, const string &ad) : name(n), address(ad){};
    Person(istream& is){
        read_person(is, *this);
    }
    // 成员函数
    string& getName() { return name; }
    string& getAddress() { return address; }
    // 成员变量
    string name;
    string address;
};

istream& read_person(istream& is, Person& p){
    is >> p.name >> p.address;
    return is;
}

ostream& print_person(ostream& os, const Person& p){
    os << p.name << " " << p.address << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    // 7.3
    // Sales_data total;
    // if (read(cin, total)){
    //     Sales_data trans;
    //     while (read(cin, trans)){
    //         if (total.isbn() == trans.isbn()){
    //             total.combine(trans);
    //         } else {
    //             print(cout, total);
    //             total = trans;
    //         }
    //     }
    //     print(cout, total);
    // } else {
    //     cerr << "No data input" << endl;
    // }

    // 7.9
    // Person p1, p2;
    // read_person(read_person(cin, p1), p2);
    // print_person(cout, p1);
    // print_person(cout, p2);

    // 7.11
    // Sales_data s0;
    // print(cout, s0);
    // Sales_data s1("abc");
    // print(cout, s1);
    // Sales_data s2("def", 1, 1);
    // print(cout, s2);
    // Sales_data s3(cin);
    // print(cout, s3);

    // 7.13
    // Sales_data total(cin);
    // if (cin){
    //     while (cin){
    //         Sales_data trans(cin);
    //         if (total.isbn() == trans.isbn()){
    //             total.combine(trans);
    //         } else {
    //             print(cout, total);
    //             total = trans;
    //         }
    //     }
    // } else {
    //     cerr << "No data input" << endl;
    // }

    // 7.15
    Person p0;
    print_person(cout, p0);
    Person p1("jw", "beijing");
    print_person(cout, p1);
    Person p2(cin);
    print_person(cout, p2);

    return 0;
}
