#pragma once

#include <cassert>

enum class NODE_TYPE
{
	PARENT, // 0
	LCHILD, // 1
	RCHILD, // 2
	END,	// 3
};

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
	tBSTNode* arr_node[(int)NODE_TYPE::END];

	tBSTNode()
		: pair()
		, arr_node{ nullptr, nullptr, nullptr}
	{}

	tBSTNode(const tPair<T1, T2> _pair, tBSTNode* _parent_node, tBSTNode* _lchild_node, tBSTNode* _rchild_node)
		: pair(_pair)
		, arr_node{ _parent_node, _lchild_node, _rchild_node }
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
				if (nullptr == node->arr_node[(int)NODE_TYPE::RCHILD])
				{
					node->arr_node[(int)NODE_TYPE::RCHILD] = new_node;
					new_node->arr_node[(int)NODE_TYPE::PARENT] = node;
					break;
				}
				else
				{
					node = node->arr_node[(int)NODE_TYPE::RCHILD];
				}
			}
			else if (_pair.first < node->pair.first)
			{
				if (nullptr == node->arr_node[(int)NODE_TYPE::LCHILD])
				{
					node->arr_node[(int)NODE_TYPE::LCHILD] = new_node;
					new_node->arr_node[(int)NODE_TYPE::PARENT] = node;
					break;
				}
				else
				{
					node = node->arr_node[(int)NODE_TYPE::LCHILD];
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
