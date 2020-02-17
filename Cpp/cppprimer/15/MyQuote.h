#ifndef _MY_QUOTE_H
#define _MY_QUOTE_H
#include <iostream>
#include <string>
#include <utility>

/*****************************************/
/**************** MyQuote ****************/
/*****************************************/
class MyQuote {
public:
    MyQuote() = default;
    MyQuote(const std::string &book, double sales_price) : bookNo(book), price(sales_price){};
    MyQuote(const MyQuote &rmq) : bookNo(rmq.bookNo), price(rmq.price) 
        { std::cout << "MyQuote(const MyQuote &rmq)" << std::endl; }
    MyQuote(MyQuote &&rmq) noexcept : bookNo(std::move(rmq.bookNo)), price(std::move(rmq.price))
        { std::cout << "MyQuote(MyQuote &&rmq) noexcept" << std::endl; }
    MyQuote &operator=(const MyQuote &rmq);
    MyQuote &operator=(MyQuote &&rmq) noexcept;
    virtual ~MyQuote() { std::cout << "~MyQuote()" << std::endl; }
    std::string isbn() const { return bookNo; }
    virtual MyQuote* clone() const & { return new MyQuote(*this); }
    virtual MyQuote *clone() const && { return new MyQuote(std::move(*this)); }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual std::ostream &debug(std::ostream &os) const 
        { os << "bookNo: " << bookNo << " price:" << price; return os; }

private:
    std::string bookNo;

protected:
    double price;
};

MyQuote &MyQuote::operator=(const MyQuote &rmq) {
    bookNo = rmq.bookNo;
    price = rmq.price;
    std::cout << "MyQuote &MyQuote::operator=(const MyQuote &rmq)" << std::endl;
    return *this;
}

MyQuote &MyQuote::operator=(MyQuote &&rmq) noexcept {
    bookNo = std::move(rmq.bookNo);
    price = std::move(rmq.price);
    std::cout << "MyQuote &MyQuote::operator=(MyQuote &&rmq) noexcept " << std::endl;
    return *this;
}

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
    MyDiscQuote(const MyDiscQuote &rmdq) : 
        MyQuote(rmdq), quantity(rmdq.quantity), discount(rmdq.discount)
        { std::cout << "MyDiscQuote(const MyDiscQuote &rmdq)" << std::endl; } 
    MyDiscQuote(MyDiscQuote &&rmdq) noexcept : 
        MyQuote(std::move(rmdq)), quantity(std::move(rmdq.quantity)), discount(std::move(rmdq.discount)) 
        { std::cout << "MyDiscQuote(MyDiscQuote &&rmdq) noexcept " << std::endl; }
    MyDiscQuote &operator=(const MyDiscQuote &rmdq);
    MyDiscQuote &operator=(MyDiscQuote &&rmdq) noexcept;
    ~MyDiscQuote() override { std::cout << "~MyDiscQuote()" << std::endl; }
    MyDiscQuote *clone() const & = 0;
    MyDiscQuote *clone() const && = 0;
    double net_price(std::size_t n) const = 0;
    std::ostream &debug(std::ostream &os) const = 0;
};

MyDiscQuote &MyDiscQuote::operator=(const MyDiscQuote &rmdq) {
    MyQuote::operator=(rmdq);
    quantity = rmdq.quantity;
    discount = rmdq.discount;
    std::cout << "MyDiscQuote &MyDiscQuote::operator=(const MyDiscQuote &rmdq)" << std::endl;
    return *this;
}

MyDiscQuote &MyDiscQuote::operator=(MyDiscQuote &&rmdq) noexcept {
    MyQuote::operator=(std::move(rmdq));
    quantity = std::move(rmdq.quantity);
    discount = std::move(rmdq.discount);
    std::cout << "MyDiscQuote &MyDiscQuote::operator=(MyDiscQuote &&rmdq) noexcept" << std::endl;
    return *this;
}

/*****************************************/
/************** MyBulkQuote **************/
/*****************************************/
class MyBulkQuote: public MyDiscQuote {
public:
    MyBulkQuote() = default;
    using MyDiscQuote::MyDiscQuote;
    // MyBulkQuote(const std::string &book, double sales_price, std::size_t min_q, double discnt) : 
    //     MyDiscQuote(book, sales_price, min_q, discnt){};
    MyBulkQuote(const MyBulkQuote &rmbq) : MyDiscQuote(rmbq) 
        { std::cout << "MyBulkQuote(const MyBulkQuote &rmbq)" << std::endl; }
    MyBulkQuote(MyBulkQuote &&rmbq) noexcept : MyDiscQuote(std::move(rmbq))
        { std::cout << "MyBulkQuote(MyBulkQuote &&rmbq) noexcept" << std::endl; }
    MyBulkQuote &operator=(const MyBulkQuote &rmbq);
    MyBulkQuote &operator=(MyBulkQuote &&rmbq) noexcept;
    ~MyBulkQuote() override { std::cout << "~MyBulkQuote()" << std::endl; }
    MyBulkQuote *clone() const & override { return new MyBulkQuote(*this); }
    MyBulkQuote *clone() const && override { return new MyBulkQuote(std::move(*this)); }
    double net_price(std::size_t n) const override;
    std::ostream &debug(std::ostream &os) const override;
};

MyBulkQuote& MyBulkQuote::operator=(const MyBulkQuote &rmbq) {
    MyDiscQuote::operator=(rmbq);
    std::cout << "MyBulkQuote& MyBulkQuote::operator=(const MyBulkQuote &rmbq)" << std::endl;
    return *this;
}

MyBulkQuote &MyBulkQuote::operator=(MyBulkQuote &&rmbq) noexcept {
    MyDiscQuote::operator=(std::move(rmbq));
    std::cout << "MyBulkQuote &MyBulkQuote::operator=(MyBulkQuote &&rmbq) noexcept" << std::endl;
    return *this;
}

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
