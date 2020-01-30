#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>

class MyStrBlob{
public:
    using T = int;
    MyStrBlob() : data(std::make_shared<std::vector<T>>()){};
    MyStrBlob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)){};
    size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &e) { data->push_back(e); }
    void pop_back() { data->pop_back(); }
    T &front() { return data->front(); }
    T &back() { return data->back(); }
    const T &front() const { return data->front(); }
    const T &back() const { return data->back(); }

private:
    std::shared_ptr<std::vector<T>> data;
};
