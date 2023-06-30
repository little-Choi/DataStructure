#pragma once
#include <cassert>

template<typename T>
class CArr
{
private:
	T* pData;
	int data_count;
	int max_count;

public:
	CArr()
		: pData(nullptr)
		, data_count(0)
		, max_count(0)
	{
		pData = new T[2];
		max_count = 2;
	}

	~CArr()
	{
		if (pData)
		{
			delete[] pData;
			pData = nullptr;
		}
	}

public:
	T& operator [] (int idx)
	{
		return pData[idx];
	}

public:
	void push_back(const T& new_data);
	void resize(int resize_count);
	T* data() { return pData; }
	int size() { return data_count; }
	int capacity() { return max_count; }
	void clear();

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& iter);

	class iterator
	{
	private:
		CArr* pArr;
		T* pData;
		int idx;
		bool bValid;

	public:
		iterator()
			: pArr(nullptr)
			, pData(nullptr)
			, idx(-1)
			, bValid(false)
		{}

		iterator(CArr* _pArr, T* _pData, int _idx)
			: pArr(_pArr)
			, pData(_pData)
			, idx(_idx)
			, bValid(false)
		{
			if (-1 != idx)
				bValid = true;
		}

		~iterator()
		{}

		T& operator * ()
		{
			if (pArr->pData != pData || -1 == idx || !bValid)
				assert(nullptr);
			return pData[idx];
		}

		iterator& operator ++ ()
		{
			if (pArr->pData != pData || -1 == idx || !bValid)
				assert(nullptr);
			
			if (pArr->size() - 1 == idx)
			{
				idx = -1;
			}
			else
			{
				idx++;
			}
			return *this;
		}

		iterator operator ++ (int)
		{
			iterator copy_iter(pArr, pData, idx);

			++(*this);

			return copy_iter;

		}

		iterator& operator -- ()
		{
			if (pArr->pData != pData || 0 == idx || !bValid)
				assert(nullptr);

			if (-1 == idx)
			{
				idx = pArr->size() - 1;
			}
			else
			{
				idx--;
			}
			return *this;
		}

		iterator operator -- (int)
		{
			iterator copy_iter(pArr, pData, idx);
			--(*this);
			return copy_iter;
		}

		bool operator == (const iterator& _otheriter)
		{
			if (pArr == _otheriter.pArr && idx == _otheriter.idx)
				return true;
			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		friend class CArr;
	};

};

template<typename T>
inline void CArr<T>::push_back(const T& new_data)
{
	if (data_count >= max_count)
	{
		resize(max_count * 2);
	}

	pData[data_count++] = new_data;
}

template<typename T>
inline void CArr<T>::resize(int resize_count)
{
	T* new_data = new T[resize_count];

	for (int i = 0; i < data_count; ++i)
	{
		new_data[i] = pData[i];
	}
	delete[] pData;
	max_count = resize_count;
	pData = new_data;
}

template<typename T>
inline void CArr<T>::clear()
{
	if (pData)
	{
		delete[] pData;
		pData = nullptr;
	}
	data_count = 0;
	max_count = 0;
}

template<typename T>
inline typename CArr<T>::iterator CArr<T>::begin()
{
	if (0 == data_count)
		return iterator(this, pData, -1);
	else
		return iterator(this, pData, 0);
}

template<typename T>
inline typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, pData, -1);
}

template<typename T>
inline typename CArr<T>::iterator CArr<T>::erase(iterator& iter)
{
	if (this != iter.pArr || -1 == iter.idx || data_count <= iter.idx)
		assert(nullptr);


	for (int i = iter.idx; i < data_count - 1; ++i)
	{
		pData[i] = pData[i + 1];
	}
	iter.bValid = false;

	--data_count;

	return iterator(this, pData, iter.idx);
}
