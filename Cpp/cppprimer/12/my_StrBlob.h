#ifndef _MY_STRBLOB
#define _MY_STRBLOB
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <string>
#include <exception>

class MyStrBlobPtr;
class ConstMyStrBlobPtr;

class MyStrBlob{
    friend class MyStrBlobPtr;
    friend class ConstMyStrBlobPtr;

public:
    using T = std::string;
    MyStrBlob() : data(std::make_shared<std::vector<T>>()){};
    MyStrBlob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)){};
    size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &e) { data->push_back(e); }
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

class MyStrBlobPtr{
    friend bool equal(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2);

public:
    using T = std::string;
    MyStrBlobPtr() : curr(0){};
    MyStrBlobPtr(MyStrBlob& msb, size_t sz = 0) : wp(msb.data), curr(sz){};
    MyStrBlobPtr &incr();
    T &deref() const;

private:
    std::weak_ptr<vector<T>> wp;
    size_t curr;
    std::shared_ptr<vector<T>> check(size_t idx, const std::string msg) const;
};

std::shared_ptr<vector<MyStrBlobPtr::T>> MyStrBlobPtr::check(size_t idx, const std::string msg) const{
    auto ret = wp.lock();
    if (!ret)
        throw std::runtime_error("unbound MyStrBolPtr");
    if (idx >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

MyStrBlobPtr& MyStrBlobPtr::incr(){
    check(curr, "increased index is beyond the size of vector");
    ++curr;
    return *this;
}

MyStrBlobPtr::T& MyStrBlobPtr::deref() const{
    auto p = check(curr, "can't dereference a invaild ptr");
    return p->at(curr);
}

bool equal(const MyStrBlobPtr &p1, const MyStrBlobPtr &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr == p2.curr;
}

MyStrBlobPtr MyStrBlob::begin(){
    return MyStrBlobPtr(*this); 
}

MyStrBlobPtr MyStrBlob::end(){
    return MyStrBlobPtr(*this, data->size());
}

class ConstMyStrBlobPtr{
    friend bool equal(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2);

public:
    using T = std::string;
    ConstMyStrBlobPtr() : curr(0){};
    ConstMyStrBlobPtr(const MyStrBlob& msb, size_t sz = 0) : wp(msb.data), curr(sz){};
    ConstMyStrBlobPtr &incr();
    const T &deref() const;

private:
    std::weak_ptr<vector<T>> wp;
    size_t curr;
    std::shared_ptr<vector<T>> check(size_t idx, const std::string msg) const;
};

std::shared_ptr<vector<MyStrBlobPtr::T>> ConstMyStrBlobPtr::check(size_t idx, const std::string msg) const{
    auto ret = wp.lock();
    if (!ret)
        throw std::runtime_error("unbound MyStrBolPtr");
    if (idx >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

ConstMyStrBlobPtr& ConstMyStrBlobPtr::incr(){
    check(curr, "increased index is beyond the size of vector");
    ++curr;
    return *this;
}

const ConstMyStrBlobPtr::T& ConstMyStrBlobPtr::deref() const{
    auto p = check(curr, "can't dereference a invaild ptr");
    return p->at(curr);
}

bool equal(const ConstMyStrBlobPtr &p1, const ConstMyStrBlobPtr &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr == p2.curr;
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
