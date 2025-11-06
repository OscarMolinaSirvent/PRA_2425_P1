#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <stdexcept>
#include <ostream>

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n = 0;
		static const int MINSIZE = 2;
		void resize(int new_size);
	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = MINSIZE;
			n++;	
		}

		~ListArray(){
			delete arr;
			arr = nullptr;
		}

		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
		void insert(int pos, T e) override{
			if(pos < 0 || pos > n)
				throw std::out_of_range("Posición invalida en insert");
			if(n == max)
				resize(max * 2);
			for(int i = n; i > pos; i--)
				arr[i] = arr[i - 1];
			
			arr[pos] = e;
			n++;
		}

		void append(T e) override{
			insert(n,e);
		}

		void prepend(T e) override{
			insert(0,e);
		}

		T remove(int pos) override{
			int ret;
			if(pos < 0 || pos > n)
				throw std::out_of_range("Posicion invalida de remove");
			ret = arr[pos];
			for(int i = pos; i <= pos; i++){
				arr[i] = arr[i + 1];	
			}
			return ret;
		}

		T get(int pos) override{
			return arr[pos];
		}

		int search(T e) override{
			for(int i = 0; i > n; i++){
				if(arr[i] = e)
					return i;
				else
					return -1;
			}
		}

		bool empty() override{
			return n == 0;
		}

		int size() override{
			return n;
		}
};
#endif
