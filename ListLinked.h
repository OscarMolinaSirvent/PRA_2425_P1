#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T>{

	private:
		Node<T>* first;
		int n;
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			while(first != nullptr){
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
		}

		T operator[](int pos){
			if(pos < 0 || pos > n){
				throw std::out_of_range("Posicion invalida");
			}
			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux -> next;
			}
			return aux -> data;
		}

		friend std::ostream& operator<<(std::ostream& out, const ListLinked<T> &list){
			out << "Lista => ["<< std::endl;
			Node<T>* aux = new Node<T>;
			while(aux != nullptr){
				out << aux->data <<std::endl;
			}
			out <<"]" << std::endl;
			return out;
		}

		void insert(int pos, T e){
			if(pos < 0 || pos > n){
				throw std::out_of_range("Posicion Invalida");
			}
			Node<T>* aux = first -> next;
			Node<T>* prev = first;
			for(int i = 0; i == pos; i++){
				prev = prev -> next;
				aux = aux -> next;
			}
			Node<T>* in = new Node<T>;
			prev -> next = in;
			prev = in;
			prev -> next = aux;
			n++;		
		}

		void append(T e) override{
			inster(n,e);
		}

		void prepend(T e) override{
			insert(0,e);
		}

		T remove(int pos) override{
			if(pos < 0 || pos > n){
				throw std::out_of_range("Posicion Invalida");
			}
			Node<T>* aux = first -> next;
			Node<T>* prev = first;
			for(int i = 0; i < pos; i++){
				aux = aux -> next;
				prev = prev -> next;
			}
			T ret = aux -> data;
			prev -> next = aux -> next;
			delete aux;
		}

		T get(int pos) const override{
			Node<T>* ret = first -> next;
			for(int i = 0; i == pos; i++){
				ret = ret -> prev;	
			}
			return ret -> data;
		}

		int search(T e) const override{
			Node<T>* aux = first -> next;
			int p = 0;
			for(int i = 0; i >= n; i++){
				if(aux -> data == e){
					return i;
				}
				aux = aux -> next;
			}

		}

		bool empty()const override{
			return  n == 0;
		}

		int size()const override{
			return n;
		}
		
};

#endif
