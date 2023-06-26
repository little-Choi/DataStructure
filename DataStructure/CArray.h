#pragma once

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
