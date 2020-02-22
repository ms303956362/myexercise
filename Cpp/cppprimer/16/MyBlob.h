#ifndef _MY_BLOB
#define _MY_BLOB
#include <vector>
#include <string>
#include <exception>
#include <memory>
#include <initializer_list>
#include <utility>

template <typename T> class MyBlobPtr;
template <typename T> class MyBlob;
template <typename T> bool operator==(const MyBlob<T> &lmb, const MyBlob<T> &rmb);
template <typename T> bool operator!=(const MyBlob<T> &lmb, const MyBlob<T> &rmb);
template <typename T> bool operator<(const MyBlob<T> &lmb, const MyBlob<T> &rmb);

template <typename T>
class MyBlob {
    friend MyBlobPtr<T>;
    friend bool operator==<T>(const MyBlob<T> &lmb, const MyBlob<T> &rmb);
    friend bool operator!=<T>(const MyBlob<T> &lmb, const MyBlob<T> &rmb);
    friend bool operator< <T>(const MyBlob<T> &lmb, const MyBlob<T> &rmb);

public:
    /*********普通构造函数**********/
    MyBlob() : data(std::make_shared<std::vector<T>>()){};
    MyBlob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)){};
    /*********拷贝控制函数**********/
    MyBlob(const MyBlob &rmb) : data(std::make_shared<std::vector<T>>(*rmb.data)){};
    MyBlob(const MyBlob &&rmb) : data(std::move(rmb.data)){};
    MyBlob &operator=(const MyBlob &rmb) { data = std::make_shared<std::vector<T>>(*rmb.data); return *this;}
    MyBlob &operator=(const MyBlob &&rmb) { data = std::move(rmb.data); return *this; }
    ~MyBlob() = default;
    /*********普通成员函数**********/
    size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &e) { data->push_back(e); }
    void push_back(T &&e) { data->push_back(std::move(e)); }
    void pop_back() { data->pop_back(); }
    T &front() { return data->front(); }
    T &back() { return data->back(); }
    const T &front() const { return data->front(); }
    const T &back() const { return data->back(); }
    T &operator[](size_t n) { return (*data)[n]; }
    const T &operator[](size_t n) const { return (*data)[n]; }
    MyBlobPtr<T> begin();
    MyBlobPtr<T> end();

private:
    void check(size_t idx, const std::string &msg) const;
    std::shared_ptr<std::vector<T>> data;
};

template <typename T>
void MyBlob<T>::check(size_t idx, const std::string &msg) const{
    if (idx >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
bool operator==(const MyBlob<T> &lmb, const MyBlob<T> &rmb){
    return *lmb.data == *rmb.data;
}

template <typename T>
bool operator!=(const MyBlob<T> &lmb, const MyBlob<T> &rmb){
    return !(lmb == rmb);
}

template <typename T>
bool operator<(const MyBlob<T> &lmb, const MyBlob<T> &rmb){
    return *lmb.data < *rmb.data;
}

/**************class MyBlobPtr****************/
template <typename T> bool operator==(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);
template <typename T> bool operator!=(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);
template <typename T> bool operator<(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);
template <typename T> MyBlobPtr<T> operator+(const MyBlobPtr<T> &p1, size_t n);
template <typename T> MyBlobPtr<T> operator-(const MyBlobPtr<T> &p1, size_t n);
template <typename T> long long operator-(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);

template <typename T>
class MyBlobPtr {
    friend bool operator==<T>(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);
    friend bool operator!=<T>(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);
    friend bool operator< <T>(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);
    friend MyBlobPtr<T> operator+<T>(const MyBlobPtr<T> &p1, size_t n);
    friend MyBlobPtr<T> operator-<T>(const MyBlobPtr<T> &p1, size_t n);
    friend long long operator-<T>(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2);

public:
    /*********普通构造函数**********/
    MyBlobPtr() : curr(0){};
    MyBlobPtr(MyBlob<T>& mb, size_t sz = 0) : wp(mb.data), curr(sz){};
    /*********普通成员函数**********/
    MyBlobPtr &operator++();
    MyBlobPtr operator++(int);
    MyBlobPtr &operator--();
    MyBlobPtr operator--(int);
    MyBlobPtr& operator+=(size_t n);
    MyBlobPtr& operator-=(size_t n);
    T &operator*() const;
    T *operator->() const;

private:
    std::weak_ptr<std::vector<T>> wp;
    size_t curr;
    std::shared_ptr<std::vector<T>> check(size_t idx, const std::string msg) const;
};

template <typename T>
std::shared_ptr<std::vector<T>> MyBlobPtr<T>::check(size_t idx, const std::string msg) const{
    auto ret = wp.lock();
    if (!ret)
        throw std::runtime_error("unbound MyStrBolPtr");
    if (idx >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
bool operator==(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr == p2.curr;
}

template <typename T>
bool operator!=(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2){
    return !(p1 == p2);
}

template <typename T>
bool operator<(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2){
    if (p1.wp.lock() != p2.wp.lock())
        throw std::runtime_error("not pointed to same vector");
    else
        return p1.curr < p2.curr;
}

template <typename T>
MyBlobPtr<T> &MyBlobPtr<T>::operator++(){
    check(curr, "increased index is beyond the size of vector");
    ++curr;
    return *this;
}

template <typename T>
MyBlobPtr<T> MyBlobPtr<T>::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T>
MyBlobPtr<T> &MyBlobPtr<T>::operator--(){
    --curr;
    check(curr, "decreament past beyond the begining index");
    return *this;
}

template <typename T>
MyBlobPtr<T> MyBlobPtr<T>::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T>
MyBlobPtr<T>& MyBlobPtr<T>::operator+=(size_t n){
    check(curr + n, "increased index is beyond the size of vector");
    curr += n;
    return *this;
}

template <typename T>
MyBlobPtr<T>& MyBlobPtr<T>::operator-=(size_t n){
    check(curr - n, "decreament past beyond the begining index");
    curr -= n;
    return *this;
}

template <typename T>
MyBlobPtr<T> operator+(const MyBlobPtr<T> &p1, size_t n){
    MyBlobPtr<T> p2 = p1;
    p2 += n;
    return p2;
}

template <typename T>
MyBlobPtr<T> operator-(const MyBlobPtr<T> &p1, size_t n){
    MyBlobPtr<T> p2 = p1;
    p2 -= n;
    return p2;
}

template <typename T>
long long operator-(const MyBlobPtr<T> &p1, const MyBlobPtr<T> &p2){
    if (p1.curr > p2.curr)
        return p1.curr - p2.curr;
    else
        return -(p2.curr - p1.curr);
}

template <typename T>
T &MyBlobPtr<T>::operator*() const{
    auto p = check(curr, "can't dereference a invaild ptr");
    return (*p)[curr];
}

template <typename T>
T *MyBlobPtr<T>::operator->() const{
    return &(this->MyBlobPtr<T>::operator*());
}

template <typename T>
MyBlobPtr<T> MyBlob<T>::begin(){
    return MyBlobPtr<T>(*this); 
}

template <typename T>
MyBlobPtr<T> MyBlob<T>::end(){
    return MyBlobPtr<T>(*this, data->size());
}

#endif
