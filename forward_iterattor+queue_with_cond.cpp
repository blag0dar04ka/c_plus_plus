


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>


using namespace std;

template<class T>
struct PQnode {
	T value;
	int prior;
	PQnode<T> *next;

	PQnode(T val, int p_val) {
		value = val;
		prior = p_val;
		next = nullptr;
	}

	void operator = (PQnode<T> &node) {
		value = node.value;
		prior = node.prior;
		next = node.next;
	}
};

template<class T>
class PQueue {
public:
	PQnode<T> *head;
	PQnode<T> *tail;
	struct Pred {
		bool operator()(int i) { return i < 6; }//приоритет меньше 6
	};

	PQueue() { head = tail = nullptr; }

	class ForwardIterator {
	public:

		ForwardIterator() { 
			ptr = nullptr; 
		}

		void operator = (PQnode<T>* node) { ptr = node; }
		bool operator != (ForwardIterator it) { return ptr != it.ptr; }
		bool operator == (ForwardIterator it) { return ptr == it.ptr; }

		ForwardIterator(PQnode<T>* node) {
			Pred pred;

			if (!node) ptr = nullptr; 

			else if (pred(node->prior)) ptr = node;

			else ptr = nullptr;
		}
		T& operator*() { return ptr->value; }
		ForwardIterator operator++() {
			if (ptr) {
				ptr = ptr->next;
				if (ptr) {
					Pred pred;
					if (!pred(ptr->prior)) this->ptr = nullptr;
					
				}
			}
			return *this;
		}


		PQnode<T>* ptr;
	};

	ForwardIterator begin() { return ForwardIterator(head); }
	ForwardIterator end() { return ForwardIterator(tail->next); }
	void push_back(T val, int p_val)
	{
		if (!head) {
			head = new PQnode<T>(val, p_val);
			head->next = nullptr;
			tail = head;
			return;
		}

		PQnode<T> *new_node = new PQnode<T>(val, p_val);

		if (head->prior > new_node->prior) {
			new_node->next = head;
			head = new_node;
			return;
		}

		PQnode<T> *head_ = head;
		PQnode<T> *next_ = head->next;

		while (next_) {
			if (next_->prior > new_node->prior) {
				head_->next = new_node;
				new_node->next = next_;
				return;
			}
			head_ = next_;
			next_ = next_->next;
		}

		tail->next = new_node;
		tail = new_node;
	}
};


int main()
{
	PQueue<string> queue;
	//вывод элементов приоритет которых меньше чем 6
	queue.push_back("kot kokos", 2);
	queue.push_back("mish gashish", 1);
	queue.push_back("komar escobar", 6);
	queue.push_back("slon meffedron", 20);
	for (PQueue<string>::ForwardIterator i = queue.begin(); i != queue.end(); ++i)
		std::cout << *i << endl;
	return 0;
}