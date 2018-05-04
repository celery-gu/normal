#include "list.h"
#include <cassert>

template <typename T>
const T& List<T>::front() {
    return _head->getNext()->getValue();
}

template <typename T>
const T& List<T>::back() {
    return _head->getPrev()->getValue();
}

template <typename T>
NodeIter<T> List<T>::begin() {
    return NodeIter<T>(_head->getNext());
}

template <typename T>
NodeIter<T> List<T>::end() {
    return NodeIter<T>(_head);
}

template <typename T>
const T& List<T>::cur() {
    return _cur->getValue();
}

template <typename T>
void List<T>::next() {
    _cur = _cur->getNext();
}

template <typename T>
void List<T>::before() {
    _cur = _cur->getPrev();
}

template <typename T>
void List<T>::insert_next(const T& next) {
    cur->insertNext(next);
    _size++;
}

template <typename T>
void List<T>::insert_before(const T& before) {
    _size++;
    this->insertBefore(before);
}

template <typename T>
void List<T>::erase_next() {
    _size--;
    this->removeNext();
}

template <typename T>
void List<T>::erase_before() {
    _size--;
    this->removeBefore();
}

template <typename T>
void List<T>::push_back(const T& back) {
   _head->insertBefore(back);
    _size++;
}

template <typename T>
void List<T>::push_front(const T& front) {
   _head->insertNext(front);
    _size++;
}

template <typename T>
void List<T>::pop_back() {
   _head->removeBefore();
    _size--;
}

template <typename T>
void List<T>::pop_front() {
   _head->removeNext();
    _size--;
}

template <typename T>
List<T>::List() : _size(0) {
    _head = new Node<T>();
    assert(empty());
    reset();
}

template <typename T>
List<T>::~List() {
    clear();
    assert(size() == 0);
    delete _head;
}
template <typename T>
bool List<T>::empty() {
    return begin() == end();
}

#include <iostream>
template <typename T>
void List<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

template <typename T>
void List<T>::print() {
    Iterator temp = begin();
    for (;temp != end(); ++temp) {
        std::cout<<*temp<<std::endl;
    }
}
template <typename T> 
void List<T>::reset() {
    _cur = _head->getNext();
}

template <typename T>
unsigned List<T>::size() {
    return _size;
}

template <typename T>
NodeIter<T> List<T>::find(T value) {
    for (List<T>::Iterator iter = begin(); iter != end(); ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return end();
}

template <typename T>
void List<T>::insert(Iterator&  iter, T value) {
    iter.insert_before(value);
    _size++;
}

template <typename T>
void List<T>::erase(const Iterator& iter) {
    const_cast<Iterator&>(iter).remove().free();
    _size--;
}

template <typename T>
bool List<T>::remove(const T& value) {
    for (Iterator iter = begin(); iter != end(); ++iter) {
        if (*iter == value) {
            erase(iter);
            return true;
        }
    }
    return false;
}

template <typename T>
bool List<T>::remove_if(bool (*p)(Iterator&)) {
    for (Iterator iter = begin(); iter != end(); ++iter) {
        if (p(iter)) {
            erase(iter);
            return true;
        }
    }
    return false;
}

template <typename T>
void List<T>::sort() {
    Iterator bg = begin();
    Iterator ed = ++begin();
    Iterator tmp; 
    while (bg != --end()) {
        if (*ed >= *bg) {
            ++bg;
            ++ed;
            continue;
        }
        tmp = bg;
        while (tmp != begin() && *ed < *(--tmp));
        if (tmp == begin() && *tmp > *ed) {
            tmp.emplace_before(ed.remove());
        }
        else {
            tmp.emplace_after(ed.remove());
        }
        ed = ++bg;
        --bg;
    }
}

template <typename T>
void List<T>::reverse() {
    int s = _size;
    Node<T>* bg = _head->getNext();
    while (--s) {
        _head->insertNext(bg->removeNext());
    }
}

template <typename T>
void List<T>::splice(List<T>& lst) {
    for (Iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        push_back(*iter);
    }
}

template <typename T>
void List<T>::copy(Iterator bg, Iterator ed, Iterator pt) {
    for (;;) {
        insert(pt, *bg);
        ++bg;
        if (bg == ed) {
            break;
        }
    }
}
