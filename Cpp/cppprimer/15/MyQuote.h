#ifndef _MY_QUOTE_H
#define _MY_QUOTE_H
#include <iostream>
#include <string>

/*****************************************/
/**************** MyQuote ****************/
/*****************************************/
class MyQuote {
public:
    MyQuote() = default;
    MyQuote(const std::string &book, double sales_price) : bookNo(book), price(sales_price){};
    std::string isbn() const { return bookNo; }
    virtual ~MyQuote() = default;
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual std::ostream &debug(std::ostream &os) const { os << "bookNo: " << bookNo << " price:" << price; return os; }

private:
    std::string bookNo;

protected:
    double price;
};

double print_total(std::ostream& os, const MyQuote& mq, std::size_t n){
    double total_price = mq.net_price(n);
    os << "ISBN: " << mq.isbn() << " # sold: " << n << " total due: " << total_price << std::endl;
    return total_price;
}

/*****************************************/
/************** MyDiscQuote **************/
/*****************************************/
class MyDiscQuote: public MyQuote {
protected:
    std::size_t quantity = 0;
    double discount = 0.0;

public:
    MyDiscQuote() = default;
    MyDiscQuote(const std::string &book, double sales_price, std::size_t qty, double discnt) : 
        MyQuote(book, sales_price), quantity(qty), discount(discnt){};
    double net_price(std::size_t n) const = 0;
    std::ostream &debug(std::ostream &os) const = 0;
};

/*****************************************/
/************** MyBulkQuote **************/
/*****************************************/
class MyBulkQuote: public MyDiscQuote {
public:
    MyBulkQuote() = default;
    MyBulkQuote(const std::string &book, double sales_price, std::size_t min_q, double discnt) : 
        MyDiscQuote(book, sales_price, min_q, discnt) {};
    double net_price(std::size_t n) const override;
    std::ostream &debug(std::ostream &os) const override;
};

double MyBulkQuote::net_price(std::size_t n) const {
    if (n >= quantity)
        return n * discount * price;
    else
        return n * price;
}

std::ostream &MyBulkQuote::debug(std::ostream &os) const {
    MyQuote::debug(os);
    os << " min_qty: " << quantity << " discount: " << discount;
    return os;
}

/********************************************/
/************** MyBulkQuotemax **************/
/********************************************/
class MyBulkQuotemax: public MyDiscQuote
{
protected:
    std::size_t max_qty = 0;

public:
    MyBulkQuotemax() = default;
    MyBulkQuotemax(const std::string &book, double sales_price, std::size_t min_q, std::size_t max_q, double discnt) : 
        MyDiscQuote(book, sales_price, min_q, discnt), max_qty(max_q){};
    double net_price(std::size_t n) const override;
    std::ostream &debug(std::ostream &os) const override;
};

double MyBulkQuotemax::net_price(std::size_t n) const {
    if (n <= quantity)
        return n * price;
    else if (n <= max_qty)
        return n * discount * price;
    else
        return max_qty * discount * price + (n - max_qty) * price;
}

std::ostream &MyBulkQuotemax::debug(std::ostream &os) const {
    MyQuote::debug(os);
    os << " min_qty: " << quantity << " discount: " << discount;
    os << " max_qty: " << max_qty;
    return os;
}

#endif
