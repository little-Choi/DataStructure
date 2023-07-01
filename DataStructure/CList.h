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

	}
};