#include <iostream>
#include <stdio.h>
#include <vector>

#include "CArray.h"

using std::vector;

int main()
{
	// vector ±¸Çö
	{
		vector<int> vecInt;
		vecInt.push_back(10);
		vecInt.push_back(20);
		vecInt.push_back(30);
		vecInt.resize(10);

		int* a1 = vecInt.data();
		int a2 = vecInt[1];
		int a3 = vecInt.size();

		CArr<int> arrInt;
		arrInt.push_back(10);
		arrInt.push_back(20);
		arrInt.push_back(30);
		arrInt.resize(10);
		int* b1 = arrInt.data();
		int b2 = arrInt[1];
		int b3 = arrInt.size();
		arrInt.clear();

		int k = 0;
	}





	return 0;
}