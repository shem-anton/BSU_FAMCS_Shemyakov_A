#include <cstdlib>
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
T & Merge_Sort(T &arg)
{
     /*for(typename T::iterator it = arg.begin(); it != arg.end(); ++it)
     cout<<(*it)<<"  "; 
     cout<<endl;      
     system("PAUSE");*/
     if(arg.size()>2)
     {            
         T a, b;
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

    system("PAUSE");
    return EXIT_SUCCESS;
}
