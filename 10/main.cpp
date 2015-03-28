#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

ifstream fin("input.txt");

struct Value
{
	string key;
	int arrival, duration;
	string data;
	Value(string a, int b, int c, string d): key(a), arrival(b), duration(c), data(d){};
	Value(){};
};

void for_4_task(Value a)
{
	if(a.key=="test")
	cout<<a.data<<endl;
}

template <typename T>
class Cash
{
	struct Value
{
	T key;
	int arrival, duration;
	string data;
	Value(T a, int b, int c, string d): key(a), arrival(b), duration(c), data(d){};
};
public:
	void update(T key, string value, int startTime, int timeout)
	{
		auto it = records.begin();
		for(; it != records.end(); ++it)
		{
			if((*it).key==key)
			break;
		}
		if(it == records.end())
		{
			Value temp(key, startTime, timeout, value);
			records.push_back(temp);
		}
		else
		if(startTime > (*it).arrival)
		{
			(*it).arrival = startTime;
			(*it).duration = timeout;
			(*it).data = value;
		}
	}

	string getvalue(T key, int curTime)
	{
		auto it = records.begin();
		for(; it != records.end(); ++it)
		{
			if(((*it).key == key) && ((*it).arrival + (*it).duration > curTime) && ((*it).arrival <= curTime))
			return (*it).data;
		}
		if(it == records.end())
			return "";
	}

	bool contains (T key, int curTime)
	{
		auto it = records.begin();
		for(; it != records.end(); ++it)
		{
			if(((*it).key == key) && ((*it).arrival + (*it).duration > curTime) && ((*it).arrival <= curTime))
			return true;
		}
		return false;
	}

	int size()
	{
		return records.size();
	}
private:
	vector<Value> records;
};

int main(int argc, char *argv[])
{	
	Cash<string> MyCash;
	Cash<int> MyCashInt;
	vector <Value> cash;
	set <string> for_2_task;
	vector <int> for_3_task;
	int record;
	fin >> record;
	Value temp;
	int i=0;
	while(!fin.eof())
	{
		i++;
		fin >> temp.key >> temp.arrival >> temp.duration >> temp.data;
		for_2_task.insert(temp.key);
		for_3_task.push_back(temp.duration);
		cash.push_back(temp);
		MyCash.update(temp.key, temp.data, temp.arrival, temp.duration);
		MyCashInt.update(i, temp.data, temp.arrival, temp.duration);
	}
	
	cout << for_2_task.size()<<endl;
	
	cout << *(max_element(for_3_task.begin(), for_3_task.end())) << endl;
	
	for_each(cash.begin(), cash.end(), for_4_task);
	
	sort(cash.begin(), cash.end(), [](Value a, Value b)->bool{return (a.arrival + a.duration) < (b.arrival + b.duration);});
	
	cout << MyCash.getvalue("tast", 2)<<endl;
	cout << MyCash.getvalue("test", 2)<<endl;
	cout << MyCash.getvalue("test", 9)<<endl;
	cout << MyCash.getvalue("abc", 17)<<endl;

	cout << MyCash.contains("abc", 3)<<endl;
	cout << MyCash.contains("abc", 18)<<endl;
	cout << MyCash.contains("tast", 18)<<endl;
	cout << MyCash.contains("test", 9)<<endl;

	cout << "Testing <int> template:\n";

	cout << MyCashInt.getvalue(2, 2)<<endl;
	cout << MyCashInt.getvalue(3, 6)<<endl;
	 
    cout << MyCashInt.contains(2, 2)<<endl;
	cout << MyCashInt.contains(3, 12)<<endl;
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
