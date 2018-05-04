#include "node.h"

template <typename T>
void Node<T>::setValue(const T& value) {
    this->value = value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* prev) {
    this->prev = prev;
}

template <typename T>
const T& Node<T>::getValue() const {
    return value;
}

template <typename T>
T& Node<T>::getValue() {
	return value;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
    return prev;
}

template <typename T>
Node<T>* Node<T>::removeNext() {
    Node<T>* next = this->getNext();
    this->setNext(next->getNext());
    next->getNext()->setPrev(this);
    return next;
}

template <typename T>
Node<T>* Node<T>::removeBefore() {
    Node<T>* before = this->getPrev();
    this->setPrev(before->getPrev());
    before->getPrev()->setNext(this);
    return before;
}

template <typename T>
void Node<T>::insertNext(const T& next) {
    Node<T>* tmp = new Node<T>(next);
    insertNext(tmp);
}

template <typename T>
void Node<T>::insertBefore(const T& before) {
    Node<T>* tmp = new Node<T>(before);
    insertBefore(tmp);
}

template <typename T>
void Node<T>::insertBefore(Node<T>* tmp) {
    this->getPrev()->setNext(tmp);
    tmp->setPrev(this->getPrev());
    this->setPrev(tmp);
    tmp->setNext(this);
}

template <typename T>
void Node<T>::insertNext(Node<T>* tmp) {
    this->getNext()->setPrev(tmp);
    tmp->setNext(this->getNext());
    this->setNext(tmp);
    tmp->setPrev(this);
}

template <typename T>
void Node<T>::reset() {
    setNext(this);
    setPrev(this);
}

template <typename T>
bool Node<T>::hasChildNode() {
    return this->getPrev() != this->getNext();
}
template <typename T>
NodeIter<T>::NodeIter() {
    ptr = 0;
}

template <typename T>
NodeIter<T>::NodeIter(Node<T>* ptr) {
    this->ptr = ptr;
}

template <typename T>
NodeIter<T>::NodeIter(const NodeIter& iter) {
    this->ptr = iter.ptr;
}

template <typename T>
NodeIter<T>::~NodeIter() {
}

template <typename T>
NodeIter<T>& NodeIter<T>::operator ++ () {
    ptr = ptr->getNext();
    return *this;
}

template <typename T>
NodeIter<T> NodeIter<T>::operator ++ (int) {
    NodeIter tmp = NodeIter(*(this));
    ptr = ptr->getNext();
    return tmp;
}

template <typename T>
NodeIter<T>& NodeIter<T>::operator -- () {
    ptr = ptr->getPrev();
    return *this;
}

template <typename T>
NodeIter<T> NodeIter<T>::operator -- (int) {
    NodeIter tmp = NodeIter(*(this));
    ptr = ptr->getPrev();
    return tmp;
}

template <typename T>
T NodeIter<T>::operator * () {
    return ptr->getValue();
}

template <typename T>
NodeIter<T> NodeIter<T>::operator = (const NodeIter<T>& iter) {
    this->ptr = iter.ptr;
    return *this;
}

template <typename T>
NodeIter<T> NodeIter<T>::remove_after() {
    return NodeIter<T>(ptr->removeNext());
}

template <typename T>
NodeIter<T> NodeIter<T>::remove_before() {
    return NodeIter<T>(ptr->removeBefore());
}

template <typename T>
void NodeIter<T>::insert_before(const NodeIter<T>& iter) {
    ptr->insertBefore(*iter);
}

template <typename T>
void NodeIter<T>::insert_before(const T& value) {
    ptr->insertBefore(value);
}

template <typename T>
void NodeIter<T>::insert_after(const NodeIter<T>& iter) {
    ptr->insertNext(*iter);
}

template <typename T>
void NodeIter<T>::insert_after(const T& value) {
    ptr->insertNext(value);
}

template <typename T>
void NodeIter<T>::emplace_after(const NodeIter<T>& iter) {
    ptr->insertNext(iter.ptr);
}

template <typename T>
void NodeIter<T>::emplace_before(const NodeIter<T>& iter) {
    ptr->insertBefore(iter.ptr);
}

template <typename T> 
NodeIter<T> NodeIter<T>::remove() {
    return NodeIter(ptr->getPrev()->removeNext());
}

template <typename T>
void NodeIter<T>::free() {
    delete ptr;
    ptr = 0;
}
