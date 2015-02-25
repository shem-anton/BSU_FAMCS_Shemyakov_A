// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

template <typename T>
bool palindrom(T container)
{
	T::iterator ti=container.end();
	T::iterator it=container.begin();
	ti--;
	int j=(container.size()+1)/2;
	//for(T::iterator it=container.begin();it!=container.end()&&ti!=container.begin();it++, ti--)
	for(int i=0;i<j;i++, ti--, it++)
		if((*it)!=(*ti))
			return false;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector <int> container1(3);
	container1[0]=1;
	container1[1]=2;
	container1[2]=1;
	list <double> container2;
	container2.push_back(5);
	container2.push_back(6);
	container2.push_back(6);
	container2.push_back(7);
	cout<<"Vector is palindrom: "<<palindrom(container1)<<endl;
	cout<<"List is palindrom: "<<palindrom(container2)<<endl;
	system("PAUSE");
	return 0;
}

