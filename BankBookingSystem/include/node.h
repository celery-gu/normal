#ifndef NODE_H
#define NODE_H
template <typename T>
class Node {
    public:
        Node() {value = T(); next = this; prev = this;}
        Node(const T &value) {this->value = value;this->next = this; this->prev = this;}
		Node(const T &value, Node<T>* prev, Node<T>* next):value(value), next(next), prev(prev) {}
        virtual ~Node() {}
        const T& getValue() const;
		T& getValue();
        Node<T>* getNext();
        Node<T>* getPrev();
        void setValue(const T& value);
        void setNext(Node<T>* next);
        void setPrev(Node<T>* prev);
        Node<T>* removeNext();
        Node<T>* removeBefore();
        void insertNext(const T& next);
        void insertNext(Node<T>* next);
        void insertBefore(const T& before);
        void insertBefore(Node<T>* before);
        void reset();
        bool hasChildNode();
    protected:
        T value;
        Node<T>* next;
        Node<T>* prev;

};

template <typename T>
class NodeIter {
    public:
        NodeIter();
        NodeIter(Node<T>* ptr);
        NodeIter(const NodeIter<T>& iter);
        virtual ~NodeIter();
        void insert_before(const T& value);
        void insert_before(const NodeIter<T>& before);
        void emplace_before(const NodeIter<T>& before);
        void insert_after(const T& value);
        void insert_after(const NodeIter<T>& after);
        void emplace_after(const NodeIter<T>& after);
        NodeIter<T> remove_before();
        NodeIter<T> remove_after();
        NodeIter<T> remove();
        NodeIter<T>& operator ++ ();
        NodeIter<T> operator ++ (int);
        NodeIter<T>& operator -- ();
        NodeIter<T> operator -- (int);
        NodeIter<T> operator = (const NodeIter<T>& iter);
        friend bool operator == (const NodeIter<T>& iter1, const NodeIter<T>& iter2) {
            return iter1.ptr == iter2.ptr;
        }

        friend bool operator != (const NodeIter<T>& iter1, const NodeIter<T>& iter2) {
			return iter1.ptr != iter2.ptr;
        }
		friend NodeIter<T> operator + (const NodeIter<T>& iter1, const unsigned num) {
			NodeIter<T> iter = iter1;
			for (unsigned i = 0; i < num; ++i) {
				++iter;
			}
			return iter;
		}
		
		T* operator ->() {
			return &(ptr->getValue());
		}
		
        T operator * ();
        void free();
    private:
        Node<T>* ptr;
};

#include "node.cpp"
#endif
