#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<iostream>
using namespace std;

const int MaxStackSize = 10000;


template <class ValType> 
class TQueue
{
	ValType *mem;
	int size;
	int begin;
	int end;
	int count;
public:
	TQueue(int _size=100);
	~TQueue();
	TQueue(const TQueue &_TStack);
	TQueue& operator=(const TQueue &_TQueue);
	bool IsEmpty();
	bool IsFull();
	ValType Pop();
	void Push(const ValType &TMP);
};

template <class ValType> TQueue<ValType>::TQueue(int _size=100)
{
	if ((_size < 1) || (_size > MaxStackSize))
		throw size;
	size = _size;
	begin = -1;
	end = 0;
	count = 0;
	mem = new ValType[_size];
}

template <class ValType> TQueue<ValType>::~TQueue()
{
	delete[] mem;
}

template <class ValType> TQueue<ValType>::TQueue(const TQueue &_TQueue) //Конструктор копирования.
{
	size = _TQueue.size;
	begin = _TQueue.begin;
	end = _TQueue.end;
	count = _TQueue.count;
	mem = new ValType[size];
	for (int i = 0; i < size; i++)
		Mem[i] = _TQueue.Mem[i];
}

template <class ValType> TQueue<ValType> &TQueue<ValType>::operator=(const TQueue &_TQueue)//оператор присваивания
{
	if (this == &_TQueue)
		return*this;
	if (size != _TQueue.size)
	{
		delete[]mem;
		mem = new ValType[_TQueue.size];
	}
	size = _TQueue.size;
	begin = _TQueue.begin;
	end = _TQueue.end;
	count = _TQueue.count;
	mem = new ValType[size];
	for (int i = 0; i < size; i++)
		mem[i] = _TQueue.mem[i];
	return *this;
}

template <class ValType> bool TQueue<ValType>::IsEmpty()
{
	return !count;
}

template <class ValType> bool TQueue<ValType>::IsFull()
{
	return count == size;
}

template <class ValType> ValType TQueue<ValType>::Pop()
{
	if(count==0)
		throw("there are no items")
	count--;
	return mem[(begin++) % size];
}

template <class ValType> void TQueue<ValType>::Push(const ValType &TMP)
{
	if (IsFull())
		throw ("full queue");
	count++;
	mem[end] = TMP;
	end = (end++) % size;
}


#endif
