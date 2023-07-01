#pragma once

template<typename T>
struct tListNode
{
	T data;
	tListNode* prev;
	tListNode* next;

	tListNode()
		: data()
		, prev(nullptr)
		, next(nullptr)
	{

	}

	tListNode(const T& new_data, tListNode<T>* new_prev, tListNode<T>* new_next)
		: data(new_data)
		, prev(new_prev)
		, next(new_next)
	{

	}

	~tListNode()
	{

	}
};


template<typename T>
class CList
{
private:
	tListNode<T>*	head_node;
	tListNode<T>*	tail_node;
	int				data_count;

public:
	CList()
		: head_node(nullptr)
		, tail_node(nullptr)
		, data_count(0)
	{

	}

	~CList()
	{
		tListNode<T>* delete_node = head_node;
		while (delete_node)
		{
			tListNode<T>* next_node = delete_node->next;
			delete delete_node;
			delete_node = next_node;
		}

	}

public:
	void push_back(const T& new_data);
	void push_front(const T& new_data);
	int size() { return data_count; }

};

template<typename T>
inline void CList<T>::push_back(const T& new_data)
{
	tListNode<T>* new_node = new tListNode<T>(new_data, nullptr, nullptr);
	
	if (0 == data_count)
	{
		head_node = new_node;
		tail_node = new_node;
	}
	else
	{
		tail_node->next = new_node;
		new_node->prev = tail_node;
		tail_node = new_node;
	}

	++data_count;
}

template<typename T>
inline void CList<T>::push_front(const T& new_data)
{
	tListNode<T>* new_node = new tListNode<T>(new_data, nullptr, nullptr);

	if (0 == data_count)
	{
		head_node = new_node;
		tail_node = new_node;
	}
	else
	{
		head_node->prev = new_node;
		new_node->next = head_node;
		head_node = new_node;
	}

	++data_count;
}
