#ifndef UNIT_1
#define UNIT_1

#include <vector>
#include <list>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T1, typename T2>
struct Pair
{
       T1 first;
       T2 second;
       Pair(T1 f, T2 s):first(f), second(s){};
};

class Route
{
public:
     bool operator==(Route a){return (type == a.type)&&(number == a.number);}
     bool operator!=(Route a){return (type != a.type)||(number != a.number);}
     bool operator<(Route a){return number < a.number;}
     bool operator>(Route a){return number > a.number;}
     Route(){};
     Route(int typ, int num):type(typ), number(num){};
     int type;
     int number;
};

class Transport
{
public:
	Transport(){routes = 0; valid_rs = 0; valid_es = 0;;}; 
      void Show();
      template <typename Iterator>
      void AddRoute(int , int , Iterator , Iterator ); 
      void DeleteRoute(int, int );
      void AddStop(string );
      void DeleteStop(string );
      Pair<list<Route>::iterator, list<Route>::iterator> GetRoutes(string ); 
      int Stops();
      int Routes();
      Pair<list<string >::iterator, list<string >::iterator > EmptyStops();
      Pair<unordered_set<int>::iterator, unordered_set<int>::iterator> RoutesList(int, int, int);
      string MaxRouts();
private:
      vector< Pair <string, list<Route> > > stops;
      int routes;
      list<string > empty_stops;
	  bool valid_rs;
	  bool valid_es;
      unordered_set<int> requred_routes;
};

template <typename Iterator>
void Transport::AddRoute(int num, int type, Iterator first, Iterator last)
{
	 valid_rs = 0;
	 valid_es = 0;
     bool check = 1;
     string temp;
     for(Iterator it = first; it != last; ++it)
     {
           temp=(*it);
           vector< Pair <string, list<Route> > >::iterator iter = stops.begin();
           for(; iter != stops.end(); ++iter)
                if(temp == (*iter).first)
                      break;
           if(iter != stops.end())
           {
               Route b(type, num); 
               if(find((*iter).second.begin(), (*iter).second.end(), b)==(*iter).second.end())
                     (*iter).second.push_back(b);
               else check = 0;
           }
           else
           {
               list<Route> b;
               b.push_back(Route(type, num));
               stops.push_back(Pair<string, list<Route> >(temp, b));                                           
           }
     }
     if(check)
          routes++;
} 
#endif
