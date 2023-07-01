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
		vector<int>::iterator veciter = vecInt.begin();
		++veciter;
		vector<int>::iterator veciter2 = vecInt.erase(veciter);
		int a1 = *veciter2;
		//*veciter;
		
		
		CArr<int> arrInt;
		arrInt.push_back(10);
		arrInt.push_back(20);
		arrInt.push_back(30);
		CArr<int>::iterator arriter = arrInt.begin();
		++arriter;
		CArr<int>::iterator arriter2 = arrInt.erase(arriter);
		int b1 = *arriter2;
		*arriter;

		


		int k = 0;
	}





	return 0;
}