#include <cstdlib>
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

template <typename T, typename C= std::stack<T> >
class Queue
{
public:
	Queue(){};
	bool empty()
	{
		return ( In.empty() && Out.empty() );
	}
	int size()
	{
		return ( In.size() + Out.size() );
	}
	T front()
	{
		if(!Out.empty())
			return Out.top();
		else
		{
			Back = In.top();
			while(!In.empty())
				{
					Out.push(In.top());
					In.pop();
				}
		}
		return Out.top();
	}
	T back()
	{
		if(!In.empty())
			return In.top();	
		else 
			return Back;
	}
	void push(T element)
	{
		In.push(element);
	}
	void pop()
	{
		if(!Out.empty())
			Out.pop();
		else
		{
		Back = In.top();
			while(!In.empty())
				{
					 Out.push(In.top());
					 In.pop();
				}
			Out.pop();
		}
	}
private:
	C In;
	C Out;
	T Back;
};

template<typename T>
T & Merge_Sort(T &arg)
{
     /*for(typename T::iterator it = arg.begin(); it != arg.end(); ++it)
     cout<<(*it)<<"  "; 
     cout<<endl;      
     system("PAUSE");*/
     if(arg.size()!=1)
     {            
         list<int> a, b;
         int n=arg.size(), i=0; 
         for(typename T::iterator it = arg.begin(); it != arg.end(); ++it)
         {
             if(i<n/2)
                  a.push_back(*it);
             else
                  b.push_back(*it);  
             i++; 
         }
         Merge_Sort(a);
         Merge_Sort(b);
         merge(a.begin(), a.end(), b.begin(), b.end(), arg.begin());
         /*for(typename T::iterator it = arg.begin(); it != arg.end(); ++it)
         cout<<(*it)<<"  ";
         cout<<endl;*/
         return arg;
     }
     else
     return arg;
}

int main(int argc, char *argv[])
{
    int a[] = {7, 2, 4, 0, 1, 8, 6, 3, 5, 9};
    list<int> test1(a,a+10);
    list<int> result = Merge_Sort(test1);
    for(list<int>::iterator it = result.begin(); it != result.end(); ++it)
    cout<<(*it)<<"  ";
    cout<<endl;
    
    Queue<int> test2;
    test2.push(1);
    test2.push(2);
    test2.push(3);
    test2.push(4);
    test2.push(5);
    cout<<"Size of queue is equal to "<<test2.size()<<endl;
    cout<<test2.front()<<" - "<<test2.back()<<endl;
    while(!test2.empty())
    {
		cout<<test2.front()<<endl;
		test2.pop();
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
