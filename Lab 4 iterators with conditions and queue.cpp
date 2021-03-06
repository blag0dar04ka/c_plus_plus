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
	
	class iterator//класс итераторса с уловием (выводит только эелементы, номера которых кратны 3
	{
	public:
		//за основу взят итератор, который лектор оставил в примере
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
		bool operator!=(const self_type& it) const { return !(it == *this); }
		bool operator()(int i) { return (i % 3) == 0; }// условие 
	};

	iterator head_it;
	iterator tail_it;
	Queue()
	{
		tail = head = new nihao(0);
		head->next = head->prev = tail;
		tail->next = tail->prev = head;
		head_it = iterator(head);
		tail_it = iterator(tail);
	}

	iterator front() { return ++head_it; }//итератор на начало
	iterator end() { return tail_it; }//итератор на конец

	void push(T m)//добавление нового элемента
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
	int by_minimum()// приоритет с наименьшего
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
	//базовое заоплнение
	for (int i = 0; i < 20;i++)
		test.push((rand()%100)+56);
	cout << "______origin_queue_____"<<endl;
	for (it = test.front(); it != test.end();++it)// вывод массива через итератор
		cout << *it << " ";
	cout << endl << endl;

	cout << "_______queue_with_condition_(even_posiyion+%3==0)______"<<endl;// вывод элементов массива с уловием

	for (it = test.front(); it != test.end(); ++it)
	{
		if (*it % 3 == 0)
		{
			if (it(3))
			{
				cout << *it << " ";

			}


		}
	}
	cout << endl << endl;
	cout << "______queue_with_priority_(ascending)_______" << endl;//вывод элементов массива в зависимости от приоритета
	for (int j = 0;j < 20;j++)
		cout << test.by_minimum() << " ";



}
