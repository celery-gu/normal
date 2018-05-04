#ifndef DEQUE_H
#define DEQUE_H

#include "list.h"
	using std::cout;
	using std::endl;
	using std::string;
	using std::ostream;
template <typename ValueType>
class deque : public List<ValueType> {
	public:
		typedef typename List<ValueType>::Iterator iterator;
		deque() {}
};

#endif
