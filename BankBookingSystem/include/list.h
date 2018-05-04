#ifndef LIST_H
#define LIST_H
#include "node.h"

template <typename T>
class List {
    public:
        typedef NodeIter<T> Iterator;
        List();
        virtual ~List();
        const T& front();
        const T& back();
        Iterator begin();
        Iterator end();
        Iterator find(T value);
        void push_back(const T& back);
        void push_front(const T& front);
        void pop_back();
        void pop_front();
        void sort();
        bool empty();
        void insert(Iterator& iter, T value);
        void erase(const Iterator& iter);
        bool remove(const T& value);
        bool remove_if(bool (*p)(Iterator&));
        void reverse();
        void splice(List<T>& list);
        void copy(Iterator bg, Iterator ed, Iterator pt);
        void clear();
        void print();
        unsigned size();
    protected:
        void reset();
        const T& cur();
        void next();
        void before();
        void insert_next(const T& next);
        void insert_before(const T& before);
        void erase_next();
        void erase_before();
        Node<T>* _head;
        Node<T>* _cur;
        unsigned _size;

};

#include "list.cpp"
#endif
