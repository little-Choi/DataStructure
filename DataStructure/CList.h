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

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& iter);
	iterator insert(const iterator& iter, const T& new_data);

	class iterator
	{
	private:
		CList<T>* pList;
		tListNode<T>* pNode; // nullptr가 end iterator
		bool bValid;

	public:
		iterator()
			: pList(nullptr)
			, pNode(nullptr)
			, bValid(false)
		{}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: pList(_pList)
			, pNode(_pNode)
			, bValid(false)
		{
			if (nullptr != _pList && nullptr != pNode)
			{
				bValid = true;
			}
		}

		~iterator()
		{}

		T& operator * ()
		{
			return pNode->data;
		}

		bool operator == (const iterator& other_iter)
		{
			if (pList == other_iter.pList && pNode == other_iter.pNode)
				return true;
			return false;
		}

		bool operator != (const iterator& other_iter)
		{
			return !(*this == other_iter);
		}

		iterator& operator ++ ()
		{
			// end인 경우
			if (nullptr == pNode || !bValid)
				assert(nullptr);
			pNode = pNode->next;
			return *this;
		}

		iterator operator ++ (int)
		{
			iterator copy_iter(*this);

			++(*this);

			return copy_iter;
		}

		iterator& operator -- ()
		{
			// begin인 경우
			if (pNode == pList->head_node || !bValid)
				assert(nullptr);
			pNode = pNode->prev;
			return *this;
		}

		iterator operator -- (int)
		{
			iterator copy_node(*this);
			--(*this);
			return copy_node;
		}

		friend class CList;
	};
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

template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, head_node);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator& iter)
{
	if (this != iter.pList || nullptr == iter.pNode)
		assert(nullptr);
	
	iter.pNode->prev->next = iter.pNode->next;
	iter.pNode->next->prev = iter.pNode->prev;
	tListNode<T>* copy_node = iter.pNode->prev;

	if (iter.pNode)
	{
		delete iter.pNode;
		iter.pNode = nullptr;

	}
	--data_count;

	return iterator(this, copy_node);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& iter, const T& new_data)
{
	if (this != iter.pList || nullptr == iter.pNode)
		assert(nullptr);

	tListNode<T>* new_node = new tListNode<T>(new_data, nullptr, nullptr);

	// iterator가 headnode 인 경우
	if (iter.pNode == head_node)
	{
		new_node->next = head_node;
		head_node->prev = new_node;
		head_node = new_node;
	}
	else
	{
		iter.pNode->prev->next = new_node;
		new_node->prev = iter.pNode->prev;
		iter.pNode->prev = new_node;
		new_node->next = iter.pNode;
	}

	++data_count;
	return iterator(this, new_node);
}
