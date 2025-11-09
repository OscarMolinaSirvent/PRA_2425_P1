#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <iostream>
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
				Node<T>* aux = first;
				first = first -> next;
				delete aux;
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
			Node<T>* aux = list.first;
			while(aux != nullptr){
				out << aux->data <<std::endl;
				aux = aux -> next;
			}
			out <<"]" << std::endl;
			return out;
		}

		void insert(int pos, T e){
			if(pos < 0 || pos > n){
				throw std::out_of_range("Posicion Invalida");
			}
			Node<T>* node = new Node<T>(e);
			if( n == 0){
				first = node;
				node -> next = nullptr;
			}
			else if(pos == 0 && n != 0){
				node -> next = first;
				first = node;
			}
			else if(pos != 0 && n != 0){
				Node<T>* prev = nullptr;
				Node<T>* aux = first;
				for(int i = 0; i < pos; i++){
					prev = aux;
					aux = aux -> next;
				}
				prev -> next = node;
				node -> next = aux;
			}
			n++;		
		}

		void append(T e) override{
			insert(n,e);
		}

		void prepend(T e) override{
			insert(0,e);
		}

		T remove(int pos) override{
			if(pos < 0 || pos > n){
				throw std::out_of_range("Posicion Invalida");
			}
			T ret = 0;
			if(pos == 0){
				Node<T>* aux = first;
				ret = first -> data;
				first = first -> next;
				delete aux;
			}
			else if(pos != 0){
			Node<T>* aux = first;
			Node<T>* prev = nullptr;
			for(int i = 0; i < pos; i++){
				prev = aux;
				aux = aux -> next;
			}
			ret = aux -> data;
			prev -> next = aux -> next;
			delete aux;
			}
			n--;
			return ret;
		}

		T get(int pos) const override{
			if(pos < 0 || pos >= n){
				throw std::out_of_range("Posición Invalida");
			}
			Node<T>* ret = first;
			for(int i = 0; i < pos; i++){
				ret = ret -> next;	
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
			}
			return -1;
		}

		bool empty()const override{
			return  n == 0;
		}

		int size()const override{
			return n;
		}
		
};

#endif
