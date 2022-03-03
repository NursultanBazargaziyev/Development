#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

// typedef
template<typename T>
struct Node {
	using node = Node<T>*;

	T data; 
	node less;
	node greater;
	node parent;
	Node(T _data, node parent = nullptr, node _greater = nullptr, node _less = nullptr) {
		data(_data);
		greater(_greater);
		less(_less);
	}
};


template<typename T>
class BinarySearch {
private:
	Node<T>* head;
	int size;
public:
	void insert(T,const Node<T>* next = head);

};

#endif

