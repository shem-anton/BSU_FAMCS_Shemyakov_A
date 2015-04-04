#include "Unit1.h"

using namespace std;

bool MaxRoutsComp(Pair <string, list<Route> > a, Pair <string, list<Route> > b)
{
     return a.second.size()<b.second.size();
}

void Transport::DeleteRoute(int num, int type)
{
	valid_rs = 0;
	valid_es = 0;
	for(vector< Pair <string, list<Route> > >::iterator iter = stops.begin(); iter != stops.end(); ++iter)
     {
           for(list<Route>::iterator it = (*iter).second.begin(); it != (*iter).second.end(); ++it)
           		if((*it)==Route(type, num))
                	  it = (*iter).second.erase(it);
     }
     routes--;
}

void Transport::Show()
{
     vector< Pair <string, list<Route> > >::iterator iter = stops.begin();
     for(; iter != stops.end(); ++iter)
     {
           cout<<endl;
           cout << (*iter).first <<":\n";
           for(list<Route>::iterator it = (*iter).second.begin(); it != (*iter).second.end(); ++it)
           {
                 string temp="";                    
                 if((*it).type == 0)
                 temp = "Tram";
                 else if((*it).type == 1)
                 temp = "Metro";
                 else if((*it).type == 2)
                 temp = "Bus";
                 else cout<<(*it).type;
                 cout<<temp<<"  "<<(*it).number<<endl;
           }
     }
}

Pair<list<Route>::iterator, list<Route>::iterator> Transport::GetRoutes(string a)
{
     vector< Pair <string, list<Route> > >::iterator iter = stops.begin();
     for(; iter != stops.end(); ++iter)
     {
         if((*iter).first == a)
         return Pair<list<Route>::iterator, list<Route>::iterator>((*iter).second.begin(),(*iter).second.end());   
     }    
	 return Pair<list<Route>::iterator, list<Route>::iterator>((*stops.begin()).second.begin(), (*stops.begin()).second.begin());    
}


void Transport::AddStop(string a)
{
	 valid_rs = 0;
	 valid_es = 0;
     vector< Pair <string, list<Route> > >::iterator iter = stops.begin();
     for(; iter != stops.end(); ++iter)
           if(a == (*iter).first)
                 break;
     if(iter == stops.end()) 
     {
            list<Route> b;
            stops.push_back(Pair<string, list<Route> >(a,b));      
     }           
}

void Transport::DeleteStop(string a)
{
	 valid_es = 0;
	 valid_rs = 0;
     vector< Pair <string, list<Route> > >::iterator iter = stops.begin();
     for(; iter != stops.end(); ++iter)
           if(a == (*iter).first)
                 break;
     if(iter != stops.end()) 
     {
            for(list<Route>::iterator it = (*iter).second.begin(); it != (*iter).second.end(); ++it)
            {
                  Route temp(*it);
                  char check = 0;
                  for(vector< Pair <string, list<Route> > >::iterator IT = stops.begin(); IT != stops.end(); ++IT)  
                  {
                        if(find((*IT).second.begin(), (*IT).second.end(), temp) != (*IT).second.end()) 
                               check++;                                                                            
                  }  
                  if(check == 1)
                  routes--;                                                
            }
            stops.erase(iter);      
     }           
}

int Transport::Stops()
{
    return stops.size();
}

int Transport::Routes()
{
    return routes;
}

string Transport::MaxRouts()
{
     return (*max_element(stops.begin(), stops.end(), MaxRoutsComp)).first;
}

Pair<list<string >::iterator, list<string >::iterator > Transport::EmptyStops()
{
	 if(valid_es)
		  return Pair<list<string >::iterator, list<string >::iterator >(empty_stops.begin(), empty_stops.end());  
     empty_stops.clear();
     vector< Pair <string, list<Route> > >::iterator iter = stops.begin();
     for(; iter != stops.end(); ++iter)
     {
         if((*iter).second.size() == 0)
         empty_stops.push_back((*iter).first);
     }    
	 	 valid_es = 1;
     return Pair<list<string >::iterator, list<string >::iterator >(empty_stops.begin(), empty_stops.end());                
}

Pair<unordered_set<int>::iterator, unordered_set<int>::iterator> Transport::RoutesList(int type, int low, int up)
{
	   if(valid_rs)
		 return Pair<unordered_set<int>::iterator, unordered_set<int>::iterator>(requred_routes.begin(), requred_routes.end()); 
       requred_routes.erase(requred_routes.begin(), requred_routes.end());                            
       for(vector< Pair <string, list<Route> > >::iterator iter = stops.begin(); iter != stops.end(); ++iter)  
       {
             for(list<Route>::iterator it = (*iter).second.begin(); it != (*iter).second.end(); ++it)
                 if((*it).type == type && (*it).number <= up && (*it).number >= low)
                      requred_routes.insert((*it).number);
       } 	   
	   valid_rs = 1;
       return Pair<unordered_set<int>::iterator, unordered_set<int>::iterator>(requred_routes.begin(), requred_routes.end()); 
}
