#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data{
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s){};
    Sales_data(const string &s, unsigned i, double d) : bookNo(s), units_sold(i), revenue(d){};
    Sales_data(istream &is) { read(cin, *this); }
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &item);
    double avg_price();

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& item){
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

inline
double Sales_data::avg_price(){
    if (units_sold != 0)
        return revenue / units_sold;
    else
        cerr << "units sold should not be 0 " << endl;
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

class Person{
    friend istream &read_person(istream &is, Person &p);
    friend ostream &print_person(ostream &os, const Person &p);

public:
    // 构造函数
    Person() = default;
    Person(const string &n, const string &ad) : name(n), address(ad){};
    Person(istream& is){
        read_person(is, *this);
    }
    // 成员函数
    string& getName() { return name; }
    string& getAddress() { return address; }

private:
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
    // 7.21
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
    // 7.22
    Person p0;
    print_person(cout, p0);
    Person p1("jw", "beijing");
    print_person(cout, p1);
    Person p2(cin);
    print_person(cout, p2);

    return 0;
}
