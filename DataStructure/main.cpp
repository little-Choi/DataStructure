#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>

#include "CArray.h"
#include "CList.h"

using std::vector;
using std::list;

int main()
{
	//// vector ����
	//{
	//	vector<int> vecInt;
	//	vecInt.push_back(10);
	//	vecInt.push_back(20);
	//	vecInt.push_back(30);
	//	vector<int>::iterator veciter = vecInt.begin();
	//	++veciter;
	//	vector<int>::iterator veciter2 = vecInt.erase(veciter);
	//	int a1 = *veciter2;
	//	//*veciter;
	//	
	//	
	//	CArr<int> arrInt;
	//	arrInt.push_back(10);
	//	arrInt.push_back(20);
	//	arrInt.push_back(30);
	//	CArr<int>::iterator arriter = arrInt.begin();
	//	++arriter;
	//	CArr<int>::iterator arriter2 = arrInt.erase(arriter);
	//	int b1 = *arriter2;
	//	*arriter;

	//	
	//	int k = 0;
	//}
	{
		list<int> listInt;
		listInt.push_back(200);
		listInt.push_back(300);
		listInt.push_front(100);
		list<int>::iterator listIter = listInt.begin();
		int a1 = *(listIter++);
		int a2 = *(++listIter);



		CList<int> mylistInt;
		mylistInt.push_back(200);
		mylistInt.push_back(300);
		mylistInt.push_front(100);
		CList<int>::iterator mylistIter = mylistInt.begin();
		int b1 = *(mylistIter++);
		int b2 = *(++mylistIter);


		int k = 0;
	}





	return 0;
}