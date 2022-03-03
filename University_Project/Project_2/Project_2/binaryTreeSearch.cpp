#include"binaryTreeSearch.h"


template<typename T>
void BinarySearch<T>::insert(T _data,const Node<T>* next)
{	

	if (size == 0)
		head = new Node<T>(_data);
	else
	{
		Node<T>* current = next;
		if (current->data <= _data)
		{
			if (!current->greater)
			{
				Node<T>* newNode = Node<T>(_data, current);
				current->greater = newNode;
			}
			else
			{

			}
		}
	}
}

