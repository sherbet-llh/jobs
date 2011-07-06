#ifndef	VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;
template <typename T> 
class Vvector
{
public:
	Vvector():vector_item(NULL),vector_size(0),vector_capacity(0)
	{
	}
	
	~Vvector()
	{
		if(vector_item != NULL)
		{
			delete []vector_item;
			vector_item = NULL;
		}
	}
	T &operator[](const int index)
	{
		return vector_item[index];
	}
	const T &operator[](const int index) const
	{
		return vector_item[index];
	}

	int size() const;
	void resize(int size);
	void reserve(int capacity);
	int capacity() const;
	bool empty() const;
	void clear();

	T front();
	T back();

	void insert(int location, const T &item);
	void erase(int location);

	void push_back(const T &item);
	void pop_back();
private:
	T *vector_item;
	int vector_size;
	int vector_capacity;
	void transfer(int capacity);
};

/*重新申请连续的空间*/
template <typename T>
void Vvector<T>::transfer(int capacity)
{	
	if(capacity < this->vector_capacity)
	{
		return;
	}
	else
	{
		this->vector_capacity = (capacity + 1) * 2;
		T *temp = new T[this->vector_capacity];
		for(int num = 0; num < this->vector_size; num ++)
		{
			temp[num] = vector_item[num];
		}
		delete []vector_item;
		vector_item = temp;
	}
}

/*返回vector的size*/
template <typename T>
int Vvector<T>::size() const
{
	return this->vector_size;
}

/*调整vector的大小，使其能容纳size个item，新元素初始化*/
template <typename T>
void Vvector<T>::resize(int size)
{
	if(size <= 0)
	{
		cout << "The size " << size << " is lower than zero!" << endl;
	}
	else if(this->vector_size >= size)
	{
		this->vector_size = size;
	}
	else if(this->vector_size < size && size <= this->vector_capacity)
	{
		while(this->vector_size < size)
		{
			vector_item[this->vector_size] = 0;//赋值--默认的初始值（？）
			this->vector_size++;
		}
	}
	else
	{
		transfer(size);
		while(this->vector_size < size)
		{
			vector_item[this->vector_size] = 0;//赋值--默认的初始值（？）
			this->vector_size++;
		}
	}
}

/*设置vector的capacity*/
template <typename T>
void Vvector<T>::reserve(int capacity)
{
	if(capacity < this->vector_capacity)
	{
		return;
	}
	else
	{
		this->vector_capacity = capacity;
		T *temp = new T[this->vector_capacity];
		for(int num = 0; num < this->vector_size; num ++)
		{
			temp[num] = vector_item[num];
		}
		delete []vector_item;
		vector_item = temp;
	}
}

/*返回vector的capacity*/
template <typename T>
int Vvector<T>::capacity() const
{
	return this->vector_capacity;
}

/*返回vector是否为空*/
template <typename T>
bool Vvector<T>::empty() const
{
	if(0 == this->vector_size)
		return 1;
	else 
		return 0;
}

/*清空vector内所有的item*/
template <typename T>
void Vvector<T>::clear()
{
	this->vector_size = 0;
}

/*返回vector的第一个item*/
template <typename T>
T Vvector<T>::front()
{
	if(empty())
	{
		cout << "The vector is empty!" << endl;
		return vector_item[0];
	}
	else
		return vector_item[0];
}

/*返回vector的最后一个item*/
template <typename T>
T Vvector<T>::back()
{
	if(empty())
	{
		cout << "The vector is empty!" << endl;
		return vector_item[0];
	}
	else
		return vector_item[vector_size-1];
}

/*在vector的固定位置插入一个item，location从0开始*/
template <typename T>
void Vvector<T>::insert(int location, const T &item)
{
	if(location > this->vector_size)
	{
		cout << "The location is overtop the size!" << endl;
	}
	else if(this->vector_capacity == this->vector_size)
	{
		transfer(this->vector_capacity);
	}
	int num = this->vector_size;
	while(num > location)
	{
		vector_item[num] = vector_item[num-1];
		num --;
	}
	vector_item[num] = item;
	this->vector_size++;
}

/*删除给定location的item，location从0开始*/
template <typename T>
void Vvector<T>::erase(int location)
{
	int num = location+1;
	if(location > this->vector_size)
	{
		cout << "The location has no item!" << endl;
		return;
	}
	else
	{
		while(num < this->vector_size)
		{
			vector_item[num-1] = vector_item[num];
			num++;
		}
		this->vector_size--;
	}
}

/*在vector的最后位置插入item*/
template <typename T>
void Vvector<T>::push_back(const T &item)
{
	if(this->vector_size == this->vector_capacity)/*The vector is full!*/
	{
		transfer(this->vector_capacity);
		vector_item[vector_size] = item;
		this->vector_size++;
	}
	else 
	{
		vector_item[vector_size] = item;
		this->vector_size++;
	}
}

/*删除vector的最后一个item*/
template <typename T>
void Vvector<T>::pop_back()
{
	if(empty())
	{
		cout<< "The vector is empty!" << endl;
		return;
	}
	else
	{
		this->vector_size--;
	}
}

#endif