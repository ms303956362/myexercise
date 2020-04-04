#pragma once

using Rank = int;

template <typename T>
class ListNode;

template <typename T>
using Posi = ListNode<T> *;

template <typename T>
class ListNode {
public:
    T data;
    Posi<T> pred;
    Posi<T> succ;
    ListNode() = default;
    ListNode(const T &e, Posi<T> p = nullptr, Posi<T> s = nullptr) : data(e), pred(p), succ(s){};
    Posi<T> insertAsPred(const T &e);
    Posi<T> insertAsSucc(const T &e);
};

template <typename T>
Posi<T> ListNode<T>::insertAsPred(const T &e) {
    Posi<T> node = new ListNode<T>(e, pred, this);
    if (pred) 
        pred->succ = node;
    pred = node;
    return node;
}

template <typename T>
Posi<T> ListNode<T>::insertAsSucc(const T &e) {
    Posi<T> node = new ListNode<T>(e, this, succ);
    if (succ) 
        succ->pred = node;
    succ = node;
    return node;
}
