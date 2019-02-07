// ConsoleApplication119.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

template <class T>
class Queue
{
public:
	struct nihao
	{
		T member;
		nihao *prev, *next;
		nihao(T v)
		{
			member = v;
			prev = 0;
			next = 0;
		}
	};
	//typedef  link;
	nihao* head;
	nihao* tail;

	class iterator
	{
	public:
		nihao* _nihao;
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef forward_iterator_tag iterator_category;
		typedef int difference_type;
		iterator() :_nihao(0) { }
		iterator(nihao * cur) : _nihao(cur) {}
		iterator(const self_type& it) : _nihao(it._nihao) {}
		self_type& operator=(const self_type& it) { _nihao = it._nihao; return *this; }
		self_type& operator++() { _nihao = _nihao->next; return *this; }
		/*self_type operator--() { self_type i = *this; ptr_--; return i; }
		self_type operator++(int junk) { ptr_++; return *this; }
		self_type operator--(int junk) { ptr_--; return *this; }*/
		reference operator*()const { return _nihao->member; }
		//pointer operator->() { return it; }
		bool operator==(const self_type& it)const { return _nihao == it._nihao; }
		bool operator!=(const self_type& it) const { return !(it==*this); }
		bool operator()(int i) {return (i % 3) == 0; }
		};
	iterator head_it;
	iterator tail_it;
	Queue()
	{
		tail=head = new nihao(0);
		head->next = head->prev = tail;
		tail->next = tail->prev = head;
		head_it = iterator(head);
		tail_it = iterator(tail);
	}

	iterator front() { return ++head_it;}
	iterator end() { return tail_it; }

	void push(T m)
	{
		nihao* n = new nihao(m);

			n->next = tail;
			n->prev = tail->prev;
			tail->prev->next = n;
			tail->prev = n;
			tail_it = iterator(tail);
		
	}
	void swap(nihao * mm, T m) { mm->key = m; }
	void del(nihao * mm)
	{
		mm->next->prev = mm->prev;
		mm->prev->next = mm->next;
		delete mm;
	}
	int by_minimum()
	{
		int min;
		nihao* temp = head->next;
		for (nihao* i = temp;i->next != head;i = i->next)
			if (temp->member > i->member)
				temp = i;
		min = temp->member;
		del(temp);
		return min;
	}
};

int main()
{
	Queue<int> test;
	Queue<int>::iterator it;
	for (int i = 0; i < 20;i++)
		test.push(rand() % 100);
	cout << "___________";
	for (it = test.front(); it != test.end();++it)
		cout << *it << " ";
	cout << endl << endl;

	cout << "_____________";
	int k = 0;
	for (it = test.front(); it != test.end();++it)
	{
		if (it(k))
			cout << *it << " ";
		k++;
	}
	cout << endl << endl;
	for (int j = 0;j < 10;j++)
		cout << test.by_minimum() << " ";



}


	













