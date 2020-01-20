#include <iostream>
#include <string>

using namespace std;

class Sales_data{
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
public:
    Sales_data(const string &s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price) {
        /*cout << "Sales_data(const string &s, unsigned cnt, double price)" << endl*/;
    }
    Sales_data(const string &s) : Sales_data(s, 0, 0){ /*cout << "Sales_data(const string &s)" << endl*/; }
    Sales_data() : Sales_data("", 0, 0){ /*cout << "Sales_data()" << endl*/; }
    Sales_data(istream &is) :Sales_data(){ 
        read(is, *this);
        // cout << "Sales_data(istream &is)" << endl;
    }
    Sales_data &combine(const Sales_data &item);

private:
    string bookNo;
    unsigned units_sold;
    double revenue;
};

Sales_data& Sales_data::combine(const Sales_data &item){
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

int main(int argc, char const *argv[])
{
    // 7.41
    // cout << "------all------" << endl;
    // Sales_data s0("abc", 2, 3);
    // cout << "------string------" << endl;
    // Sales_data s1("def");
    // cout << "------default------" << endl;
    // Sales_data s2;
    // cout << "------istream------" << endl;
    // Sales_data s3(cin);

    // 7.49
    string s = "abc";
    Sales_data i;
    i.combine(s);
    print(cout, i);

    return 0;
}
