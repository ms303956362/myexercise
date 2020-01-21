#ifndef MY_SALES_DATA_H
#define MY_SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
public:
    Sales_data(const std::string &s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price){};
    Sales_data(const std::string &s) : Sales_data(s, 0, 0){};
    Sales_data() : Sales_data("", 0, 0){};
    Sales_data(std::istream &is) :Sales_data(){ 
        read(is, *this);
    }
    std::string &isbn() { return bookNo; }
    Sales_data &combine(const Sales_data &item);

private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};


Sales_data& Sales_data::combine(const Sales_data &item){
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data& item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item){
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.revenue / item.units_sold;
    return os;
}

#endif
