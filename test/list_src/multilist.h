#ifndef _MULTI_LIST_BY_DAVID_H_
#define _MULTI_LIST_BY_DAVID_H_ 1

#include <algorithm>
#include <queue>
#include <map>
#include <bits/stl_pair.h>
using namespace std;

template <typename _Tp>
class Node
{
private:
    _Tp tp;   // value
    bool del; // deleted
public:
    friend class multilist;
    Node(/* args */);
    ~Node();
};

Node::Node(/* args */)
{
    del = false;
}

Node::~Node()
{
}

template <typename _Tp>
class multilist
{
private:
    deque<Node<_Tp> > dq;

public:
    typedef vector<_Tp>::iterator it;

    void push_back(const _Tp push);

    multilist(/* args */);
    ~multilist();
};

multilist::push_back(const _Tp push)
{
}

multilist::multilist(/* args */)
{
}

multilist::~multilist()
{
}

#endif
