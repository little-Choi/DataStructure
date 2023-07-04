#pragma once

#include <cassert>

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;

};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{ _first, _second };
}


template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair;
	tBSTNode* parent_node;
	tBSTNode* lchild_node;
	tBSTNode* rchild_node;

	tBSTNode()
		: pair()
		, parent_node(nullptr)
		, lchild_node(nullptr)
		, rchild_node(nullptr)
	{}

	tBSTNode(const tPair<T1, T2> _pair, tBSTNode* _parent_node, tBSTNode* _lchild_node, tBSTNode* _rchild_node)
		: pair(_pair)
		, parent_node(_parent_node)
		, lchild_node(_lchild_node)
		, rchild_node(_rchild_node)
	{}
};


template<typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* root_node;
	int data_count;

public:
	CBST()
		: root_node(nullptr)
		, data_count(0)
	{}

public:
	bool insert(const tPair<T1, T2>& _pair);

};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* new_node = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);
	
	if (0 == data_count)
	{
		root_node = new_node;
	}
	else
	{
		tBSTNode<T1, T2>* node = root_node;

		while (true)
		{
			if (_pair.first > node->pair.first)
			{
				if (nullptr == node->rchild_node)
				{
					node->rchild_node = new_node;
					new_node->parent_node = node;
					break;
				}
				else
				{
					node = node->rchild_node;
				}
			}
			else if (_pair.first < node->pair.first)
			{
				if (nullptr == node->lchild_node)
				{
					node->lchild_node = new_node;
					new_node->parent_node = node;
					break;
				}
				else
				{
					node = node->lchild_node;
				}
			}
			else
			{
				delete new_node;
				return false;
			}
		}

	}

	++data_count;

	return true;
}
