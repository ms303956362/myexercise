#ifndef _MY_STRBLOB
#define _MY_STRBLOB
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <string>
#include <exception>
#include <utility>

class MyStrBlobPtr;
class ConstMyStrBlobPtr;

class MyStrBlob{
    friend class MyStrBlobPtr;
    friend class ConstMyStrBlobPtr;
    friend bool operator==(const MyStrBlob &lmsb, const MyStrBlob &rmsb);
    friend bool operator!=(const MyStrBlob &lmsb, const MyStrBlob &rmsb);
    friend bool operator<(const MyStrBlob &lmsb, const MyStrBlob &rmsb);

public:
    using T = std::string;
    MyStrBlob() : data(std::make_shared<std::vector<T>>()){};
    MyStrBlob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)){};
    MyStrBlob(const MyStrBlob &rmsb) : data(std::make_shared<std::vector<T>>(*rmsb.data)){};
    MyStrBlob &operator=(const MyStrBlob &rmsb) { data = std::make_shared<std::vector<T>>(*rmsb.data); return *this; }
    std::string &operator[](size_t n) { return (*data)[n]; }
    const std::string &operator[](size_t n) const { return (*data)[n]; }
    size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &e) { data->push_back(e); }
    void push_back(T &&e) { data->push_back(std::move(e)); }
    void pop_back() { data->pop_back(); }
    T &at(std::vector<T>::size_type index) { return data->at(index); }
    const T &at(std::vector<T>::size_type index) const { return data->at(index); }
    T &front() { return data->front(); }
    T &back() { return data->back(); }
    const T &front() const { return data->front(); }
    const T &back() const { return data->back(); }
    MyStrBlobPtr begin();
    MyStrBlobPtr end();
    ConstMyStrBlobPtr cbegin() const;
    ConstMyStrBlobPtr cend() const;
    ConstMyStrBlobPtr begin() const;
    ConstMyStrBlobPtr end() const;

private:
    void check(size_t idx, const std::string &msg) const;
    std::shared_ptr<std::vector<T>> data;
};

void MyStrBlob::check(size_t idx, const std::string &msg) const{
    if (idx >= data->size())
        throw std::out_of_range(msg);
}

bool operator==(const MyStrBlob &lmsb, const MyStrBlob &rmsb){
    return *lmsb.data == *rmsb.data;
}

bool operator!=(const MyStrBlob &lmsb, const MyStrBlob &rmsb){
    return !(lmsb == rmsb);
}

bool operator<(const MyStrBlob &lmsb, const MyStrBlob &rmsb){
    return *lmsb.data < *rmsb.data;
}

class MyStrBlobPtr{
    friend bool operator==(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2);
    friend bool operator!=(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2);
    friend bool operator<(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2);
    friend MyStrBlobPtr operator+(const MyStrBlobPtr &p1, size_t n);
    friend MyStrBlobPtr operator-(const MyStrBlobPtr &p1, size_t n);
    friend long long operator-(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2);

public:
    using T = std::string;
    MyStrBlobPtr() : curr(0){};
    MyStrBlobPtr(MyStrBlob& msb, size_t sz = 0) : wp(msb.data), curr(sz){};
    MyStrBlobPtr &operator++();
    MyStrBlobPtr operator++(int);
    MyStrBlobPtr &operator--();
    MyStrBlobPtr operator--(int);
    MyStrBlobPtr& operator+=(size_t n);
    MyStrBlobPtr& operator-=(size_t n);
    T &operator*() const;
    T *operator->() const;

private:
    std::weak_ptr<std::vector<T>> wp;
    size_t curr;
    std::shared_ptr<std::vector<T>> check(size_t idx, const std::string msg) const;
};

std::shared_ptr<std::vector<MyStrBlobPtr::T>> MyStrBlobPtr::check(size_t idx, const std::string msg) const{
    auto ret = wp.lock();
    if (!ret)
        throw std::runtime_error("unbound MyStrBolPtr");
    if (idx >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

bool operator==(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr == p2.curr;
}

bool operator!=(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2){
    return !(p1 == p2);
}

bool operator<(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr < p2.curr;
}

MyStrBlobPtr &MyStrBlobPtr::operator++(){
    check(curr, "increased index is beyond the size of vector");
    ++curr;
    return *this;
}

MyStrBlobPtr MyStrBlobPtr::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}

MyStrBlobPtr &MyStrBlobPtr::operator--(){
    --curr;
    check(curr, "decreament past beyond the begining index");
    return *this;
}

MyStrBlobPtr MyStrBlobPtr::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}

MyStrBlobPtr& MyStrBlobPtr::operator+=(size_t n){
    check(curr + n, "increased index is beyond the size of vector");
    curr += n;
    return *this;
}

MyStrBlobPtr& MyStrBlobPtr::operator-=(size_t n){
    check(curr - n, "decreament past beyond the begining index");
    curr -= n;
    return *this;
}

MyStrBlobPtr operator+(const MyStrBlobPtr &p1, size_t n){
    MyStrBlobPtr p2 = p1;
    p2 += n;
    return p2;
}

MyStrBlobPtr operator-(const MyStrBlobPtr &p1, size_t n){
    MyStrBlobPtr p2 = p1;
    p2 -= n;
    return p2;
}

long long operator-(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2){
    if (p1.curr > p2.curr)
        return p1.curr - p2.curr;
    else
        return -(p2.curr - p1.curr);
}

MyStrBlobPtr::T &MyStrBlobPtr::operator*() const{
    auto p = check(curr, "can't dereference a invaild ptr");
    return (*p)[curr];
}

MyStrBlobPtr::T *MyStrBlobPtr::operator->() const{
    return &(this->operator*());
}

MyStrBlobPtr MyStrBlob::begin(){
    return MyStrBlobPtr(*this); 
}

MyStrBlobPtr MyStrBlob::end(){
    return MyStrBlobPtr(*this, data->size());
}

class ConstMyStrBlobPtr{
    friend bool operator==(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2);
    friend bool operator!=(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2);
    friend bool operator<(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2);
    friend ConstMyStrBlobPtr operator+(const ConstMyStrBlobPtr &p1, size_t n);
    friend ConstMyStrBlobPtr operator-(const ConstMyStrBlobPtr &p1, size_t n);
    friend long long operator-(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2);

public:
    using T = std::string;
    ConstMyStrBlobPtr() : curr(0){};
    ConstMyStrBlobPtr(const MyStrBlob& msb, size_t sz = 0) : wp(msb.data), curr(sz){};
    ConstMyStrBlobPtr &operator++();
    ConstMyStrBlobPtr operator++(int);
    ConstMyStrBlobPtr &operator--();
    ConstMyStrBlobPtr operator--(int);
    ConstMyStrBlobPtr& operator+=(size_t n);
    ConstMyStrBlobPtr& operator-=(size_t n);
    const T &operator*() const;
    const T *operator->() const;

private:
    std::weak_ptr<std::vector<T>> wp;
    size_t curr;
    std::shared_ptr<std::vector<T>> check(size_t idx, const std::string msg) const;
};

std::shared_ptr<std::vector<MyStrBlobPtr::T>> ConstMyStrBlobPtr::check(size_t idx, const std::string msg) const{
    auto ret = wp.lock();
    if (!ret)
        throw std::runtime_error("unbound MyStrBolPtr");
    if (idx >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

bool operator==(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr == p2.curr;
}

bool operator!=(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2){
    return !(p1 == p2);
}

bool operator<(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr < p2.curr;
}

ConstMyStrBlobPtr &ConstMyStrBlobPtr::operator++(){
    check(curr, "increased index is beyond the size of vector");
    ++curr;
    return *this;
}

ConstMyStrBlobPtr ConstMyStrBlobPtr::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}

ConstMyStrBlobPtr &ConstMyStrBlobPtr::operator--(){
    --curr;
    check(curr, "decreament past beyond the begining index");
    return *this;
}

ConstMyStrBlobPtr ConstMyStrBlobPtr::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}

ConstMyStrBlobPtr& ConstMyStrBlobPtr::operator+=(size_t n){
    check(curr + n, "increased index is beyond the size of vector");
    curr += n;
    return *this;
}

ConstMyStrBlobPtr& ConstMyStrBlobPtr::operator-=(size_t n){
    check(curr - n, "decreament past beyond the begining index");
    curr -= n;
    return *this;
}

ConstMyStrBlobPtr operator+(const ConstMyStrBlobPtr &p1, size_t n){
    ConstMyStrBlobPtr p2 = p1;
    p2 += n;
    return p2;
}

ConstMyStrBlobPtr operator-(const ConstMyStrBlobPtr &p1, size_t n){
    ConstMyStrBlobPtr p2 = p1;
    p2 -= n;
    return p2;
}

long long operator-(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2){
    if (p1.curr > p2.curr)
        return p1.curr - p2.curr;
    else
        return -(p2.curr - p1.curr);
}

const ConstMyStrBlobPtr::T &ConstMyStrBlobPtr::operator*() const{
    auto p = check(curr, "can't dereference a invaild ptr");
    return (*p)[curr];
}

const ConstMyStrBlobPtr::T *ConstMyStrBlobPtr::operator->() const{
    return &(this->operator*());
}

ConstMyStrBlobPtr MyStrBlob::cbegin() const{
    return ConstMyStrBlobPtr(*this);
}

ConstMyStrBlobPtr MyStrBlob::cend() const{
    return ConstMyStrBlobPtr(*this, data->size());
}

ConstMyStrBlobPtr MyStrBlob::begin() const{
    return ConstMyStrBlobPtr(*this);
}

ConstMyStrBlobPtr MyStrBlob::end() const{
    return ConstMyStrBlobPtr(*this, data->size());
}
#endif
