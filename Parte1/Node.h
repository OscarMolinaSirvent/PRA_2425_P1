#include <ostream>
#include "List.h"

template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>* next = nullptr){
			this -> next = next;
			this -> data = data;
		}

		friend std::ostream& operator<<(std::ostream& out, const Node<T> &node){
			out << "Data: " << node->data << std::endl;
			return out;
		}
};
