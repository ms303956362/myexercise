#ifndef MY_SALES_DATA_H
#define MY_SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data{
    friend std::istream &operator>>(std::istream &is, Sales_data &item);
    friend std::ostream &operator<<(std::ostream &os, const Sales_data &item);
    friend Sales_data operator+(Sales_data &item1, Sales_data &item2);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
public:
    Sales_data(const std::string &s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price){};
    Sales_data(const std::string &s) : Sales_data(s, 0, 0){};
    Sales_data() : Sales_data("", 0, 0){};
    Sales_data(std::istream &is) :Sales_data(){ 
        read(is, *this);
    }
    Sales_data &operator+=(Sales_data &item);
    Sales_data &operator=(const std::string &s);
    std::string &isbn() { return bookNo; }
    Sales_data &combine(const Sales_data &item);

private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

std::istream &operator>>(std::istream &is, Sales_data &item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item){
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.revenue / item.units_sold;
    return os;
}

Sales_data operator+(Sales_data &item1, Sales_data &item2){
    Sales_data sum = item1;
    sum += item2;
    return sum;
}

Sales_data &Sales_data::operator+=(Sales_data &item){
    if (bookNo == item.bookNo){
        units_sold += item.units_sold;
        revenue += item.revenue;
    } else {
        std::cerr << "bookNos are not same" << std::endl;
    }
    return *this;
}

Sales_data &Sales_data::operator=(const std::string &s){
    bookNo = s;
    units_sold = 0;
    revenue = 0;
    return *this;
}

// Sales_data operator+(Sales_data &item1, Sales_data &item2){
//     Sales_data sum = item1;
//     if (sum.bookNo == item2.bookNo){
//         sum.units_sold += item2.units_sold;
//         sum.revenue += item2.revenue;
//     } else {
//         std::cerr << "bookNos are not same" << std::endl;
//     }
//     return sum;
// }

// Sales_data &Sales_data::operator+=(Sales_data &item){
//     *this = *this + item;
//     return *this;
// }

Sales_data& Sales_data::combine(const Sales_data &item){
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data& item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item){
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.revenue / item.units_sold;
    return os;
}

#endif
